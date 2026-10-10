#!/usr/bin/env python3
"""Render the icon headers to an SVG contact sheet and check them for mistakes.

The C headers are the source of truth; this script only reads them.

Usage:
    python3 tools/render_preview.py                  # components/oli_icons/*.h -> docs/preview.svg
    python3 tools/render_preview.py --check          # also exit 1 if any errors are found
    python3 tools/render_preview.py path/to/x.h ...  # specific headers or directories

Header conventions the parser relies on:
    - One array per icon:  static const uint8_t PROGMEM name[] = { ... };
    - One line per pixel row, written as binary literals. The digits read left to
      right are the pixels: 0b00011000 (8 px), 0b11111 (HD44780, 5 px), or
      0b00000111, 0b11100000 (16 px).
    - Optional ASCII art comment per row ("// ...XX...", X = on, . = off). When
      present it sets the icon width and must match the bits.
    - Without comments, the width comes from the file name (icons_16x16.h -> 16),
      or from the number of digits in the row.
    - Icons live in namespaces (oli::icons_8x8, oli::icons_5x8 ...); names only need
      to be unique within a namespace.
    - Sets:  static const uint8_t* const <name>Set[] PROGMEM = { a, b, ... };
      Icons named <name><Suffix> (batteryCharging) are shown with the set.
    - Sections:  a /** ---- <title> ---- */ banner groups the icons after it.

Errors (fail --check):  comment/bits mismatch, bits set in row padding, ragged
rows, the same bitmap twice in a namespace (allowed when each copy is a level
in a different set), the same name twice in a namespace,
a set member that doesn't exist, a set with different level counts in
different sizes.
Warnings:  arrays that are not const; one line per size listing the icons it
lacks compared with the REFERENCE_SIZES (sizes are meant to be
interchangeable). GLYPH_SIZES (small UI glyphs) are not compared.

Standard library only.
"""

import argparse
import re
import sys
from pathlib import Path

ARRAY_RE = re.compile(
    r"static\s+(?P<const>const\s+)?uint8_t\s+(?:PROGMEM\s+)?(?P<name>\w+)\s*\[\s*\]\s*"
    r"(?:PROGMEM\s*)?=\s*\{(?P<body>.*?)\};",
    re.S,
)
SET_RE = re.compile(
    r"static\s+const\s+uint8_t\s*\*\s*const\s+(?P<name>\w+)\s*\[\s*\]\s*(?:PROGMEM\s*)?=\s*\{(?P<body>.*?)\};",
    re.S,
)
BANNER_RE = re.compile(r"/\*\*\s*\n\s*\*\s*-{10,}\s*\n\s*\*\s*([^\n]*?)\s*\n")
COMMENT_RE = re.compile(r"//[^\n]*|/\*.*?\*/", re.S)
NS_TOKEN_RE = re.compile(r"namespace\s+(\w+)\s*\{|\{|\}")
LITERAL_RE = re.compile(r"0b([01]+)")
ART_RE = re.compile(r"//\s*([X.]+)")
SIZE_RE = re.compile(r"(\d+)x(\d+)")

REPO = Path(__file__).resolve().parent.parent
REFERENCE_SIZES = {"icons_8x8"}   # their names make up the full icon set the other sizes are checked against
GLYPH_SIZES = {"icons_5x3"}       # small UI glyphs (triangles), not a size of the full icon set
FG, FG_ERR, CANVAS, MUTED = "#1b1f24", "#c0392b", "#e3e8ee", "#5b6470"
DASHED = 'fill="none" stroke="#b8c0cc" stroke-dasharray="4 3"'


# --------------------------------------------------------------------------------------------------
# Parsing
# --------------------------------------------------------------------------------------------------

def namespace_at(text):
    """Return a function mapping a text offset to the enclosing namespace path ('oli::icons_8x8')."""
    stripped = COMMENT_RE.sub(lambda m: re.sub(r"[^\n]", " ", m.group(0)), text)
    stack, marks = [], [(0, "")]
    for m in NS_TOKEN_RE.finditer(stripped):
        if m.group(1):
            stack.append(m.group(1))
        elif m.group(0) == "{":
            stack.append(None)
        elif stack:
            stack.pop()
        marks.append((m.end(), "::".join(s for s in stack if s)))

    def lookup(pos):
        ns = ""
        for p, n in marks:
            if p > pos:
                break
            ns = n
        return ns
    return lookup


def parse_header(path):
    """Return (icons, sets) parsed from one header."""
    text = path.read_text()
    size = SIZE_RE.search(path.stem)
    file_w = int(size.group(1)) if size else None
    ns_at = namespace_at(text)
    banners = [(m.start(), m.group(1)) for m in BANNER_RE.finditer(text)]

    def section_at(pos):
        title = ""
        for p, t in banners:
            if p > pos:
                break
            title = t
        return title

    icons = []
    for m in ARRAY_RE.finditer(text):
        digits, art = [], []
        for line in m.group("body").splitlines():
            literals = LITERAL_RE.findall(line.split("//")[0])
            if not literals:
                continue
            digits.append("".join(literals))
            a = ART_RE.search(line)
            art.append(a.group(1) if a else None)
        icon = build_icon(m.group("name"), bool(m.group("const")), digits, art, file_w)
        icon.update(file=path.name, line=text.count("\n", 0, m.start()) + 1,
                    ns=ns_at(m.start()), section=section_at(m.start()), order=m.start())
        icons.append(icon)

    sets = []
    for m in SET_RE.finditer(text):
        members = [t.strip() for t in COMMENT_RE.sub("", m.group("body")).split(",") if t.strip()]
        sets.append(dict(name=m.group("name"), members=members, file=path.name, ns=ns_at(m.start()),
                         line=text.count("\n", 0, m.start()) + 1, errors=[]))
    return icons, sets


def build_icon(name, is_const, digits, art, file_w):
    errors, warnings = [], []
    art_widths = {len(a) for a in art if a is not None}
    if len(art_widths) == 1 and None not in art:
        width = art_widths.pop()
    elif file_w and all(len(d) >= file_w for d in digits):
        width = file_w
    else:
        width = max((len(d) for d in digits), default=0)
    if len({len(d) for d in digits}) > 1:
        errors.append("rows have different numbers of binary digits")

    rows = []
    for y, d in enumerate(digits):
        row = "".join("X" if c == "1" else "." for c in d[:width]).ljust(width, ".")
        rows.append(row)
        if "1" in d[width:]:
            errors.append(f"row {y}: bits set in padding beyond {width} px ({d})")
        if art[y] is not None and art[y] != row:
            errors.append(f"row {y}: comment '{art[y]}' but bits draw '{row}'")
    if not is_const:
        warnings.append("not const (stored in RAM on AVR)")
    return dict(name=name, w=width, h=len(rows), rows=rows, errors=errors, warnings=warnings)


# --------------------------------------------------------------------------------------------------
# Checks across icons
# --------------------------------------------------------------------------------------------------

def is_reference_ns(ns):
    return ns.split("::")[-1] in REFERENCE_SIZES


def is_glyph_ns(ns):
    """Small UI glyphs (icons_5x3): a few shapes, not a size of the full icon set."""
    return ns.split("::")[-1] in GLYPH_SIZES


def cross_checks(icons, sets):
    """Add errors/warnings to icons and sets; return {namespace: [missing names]}."""
    by_bitmap, by_name = {}, {}
    for ic in icons:
        by_bitmap.setdefault((ic["ns"], tuple(ic["rows"])), []).append(ic)
        by_name.setdefault((ic["ns"], ic["name"]), []).append(ic)
    set_of = {(st["ns"], m): st["name"] for st in sets for m in st["members"]}
    for group in by_bitmap.values():
        owners = [set_of.get((ic["ns"], ic["name"])) for ic in group]
        if None not in owners and len(set(owners)) == len(owners):
            continue    # the same frame used as a level in different sets, e.g. both Wi-Fi styles' weakest level
        for ic in group if len(group) > 1 else []:
            ic["errors"].append("same bitmap as " + ", ".join(g["name"] for g in group if g is not ic))
    for (ns, name), group in by_name.items():
        for ic in group if len(group) > 1 else []:
            others = ", ".join(f'{g["file"]}:{g["line"]}' for g in group if g is not ic)
            ic["errors"].append(f"name '{name}' also defined at {others}")

    names_in = {}
    for ic in icons:
        names_in.setdefault(ic["ns"], set()).add(ic["name"])
    for s in sets:
        missing = [m for m in s["members"] if m not in names_in.get(s["ns"], set())]
        if missing:
            s["errors"].append("members not found: " + ", ".join(missing))

    counts = {}
    for s in sets:
        if s["ns"]:
            counts.setdefault(s["name"], {})[s["ns"]] = len(s["members"])
    for s in sets:
        c = counts.get(s["name"], {})
        if len(set(c.values())) > 1:
            s["errors"].append("level count differs between sizes: "
                               + ", ".join(f"{ns} {n}" for ns, n in sorted(c.items())))

    order = {ic["name"]: ic["order"] for ic in icons}
    reference = set().union(*(names for ns, names in names_in.items() if is_reference_ns(ns)))
    missing = {}
    for ns, names in names_in.items():
        if ns and len(names_in) > 1 and not is_glyph_ns(ns):
            lacking = sorted(reference - names, key=lambda n: order.get(n, 0))
            if lacking:
                missing[ns] = lacking
    return missing


# --------------------------------------------------------------------------------------------------
# Layout
# --------------------------------------------------------------------------------------------------

def set_base(st):
    """batterySet -> battery"""
    return st["name"][:-3] if st["name"].endswith("Set") else st["name"]


def lower_first(s):
    return s[:1].lower() + s[1:]


def esc(s):
    return s.replace("&", "&amp;").replace("<", "&lt;").replace(">", "&gt;")


class Sheet:
    char_w = 6.1   # approx. width of a 10 px monospace glyph
    gap = 14       # space between cells
    label_col = 150

    def __init__(self, scale):
        self.scale = scale
        self.parts, self.y, self.width = [], 12, 420

    def text(self, x, y, s, size=10, bold=False, fill=FG):
        weight = ' font-weight="bold"' if bold else ""
        self.parts.append(f'<text x="{x}" y="{y}" font-size="{size}"{weight} fill="{fill}">{esc(s)}</text>')
        self.width = max(self.width, x + len(s) * size * 0.61 + 12)

    def icon(self, x, y, ic):
        s, fg = self.scale, FG_ERR if ic["errors"] else FG
        self.parts.append(f'<rect x="{x}" y="{y}" width="{ic["w"] * s}" height="{ic["h"] * s}" fill="{CANVAS}"/>')
        for ry, row in enumerate(ic["rows"]):
            for run in re.finditer(r"X+", row):
                self.parts.append(f'<rect x="{x + run.start() * s}" y="{y + ry * s}" '
                                  f'width="{(run.end() - run.start()) * s}" height="{s}" fill="{fg}"/>')

    def svg(self):
        w, h = int(self.width), int(self.y)
        return (f'<svg xmlns="http://www.w3.org/2000/svg" width="{w}" height="{h}" viewBox="0 0 {w} {h}" '
                f'shape-rendering="crispEdges" font-family="ui-monospace, Menlo, Consolas, monospace">'
                f'<rect width="100%" height="100%" fill="#ffffff"/>' + "".join(self.parts) + "</svg>\n")


def legend(sheet, title):
    sheet.text(12, 28, title, size=15, bold=True)
    sheet.parts.append(f'<rect x="12" y="38" width="10" height="10" fill="{FG_ERR}"/>')
    sheet.text(28, 47, "= fails tools/render_preview.py --check", size=11)
    sheet.parts.append(f'<rect x="12.5" y="54.5" width="9" height="9" {DASHED}/>')
    sheet.text(28, 63, "= not drawn yet at that size", size=11)
    sheet.y = 80


def render_svg(icons, sets, missing, scale):
    """One block per section title. Inside it, one line per variant (each set with its special states,
    then any icons outside a set), and one row per size with the icons aligned in columns by name."""
    sheet = Sheet(scale)
    legend(sheet, f"Icon preview (x{scale})")
    namespaces = list(dict.fromkeys(ic["ns"] for ic in icons))
    ns_size, ns_of, ns_bases = {}, {}, {}
    for ic in icons:
        w, h = ns_size.get(ic["ns"], (0, 0))
        if ic["w"] * ic["h"] > w * h:
            ns_size[ic["ns"]] = (ic["w"], ic["h"])
        ns_of.setdefault(ic["name"], set()).add(ic["ns"])
    for st in sets:
        ns_bases.setdefault(st["ns"], set()).add(set_base(st))
    member_base = {m: set_base(st) for st in sets for m in st["members"]}
    missing_any = {n for names in missing.values() for n in names}
    label_col = Sheet.label_col

    def variant(name):
        """The set an icon belongs to: as a level, or as a special state named after a set of its size."""
        if name in member_base:
            return member_base[name]
        cands = [b for ns in ns_of[name] for b in ns_bases.get(ns, ())
                 if name.startswith(b) and name[len(b):][:1].isupper()]
        return max(cands, key=len) if cands else None

    def draw_line(base, names, members):
        labels = {n: lower_first(n[len(base):]) if base else n for n in names}
        if len(set(labels.values())) < len(labels):
            labels = {n: n for n in names}
        col_w = {n: max([ic["w"] * scale for ic in members if ic["name"] == n]
                        + [len(labels[n]) * Sheet.char_w]) + Sheet.gap for n in names}
        if base:
            sheet.text(24, sheet.y + 8, base + "Set", fill=MUTED)
        x = 12 + label_col
        for n in names:
            err = any(ic["errors"] for ic in members if ic["name"] == n)
            sheet.text(x, sheet.y + 8, labels[n], fill=FG_ERR if err else FG)
            x += col_w[n]
        sheet.y += 16
        not_drawn = []
        for ns in namespaces:
            row = {ic["name"]: ic for ic in members if ic["ns"] == ns and ic["name"] in col_w}
            if not row:
                if any(n in missing.get(ns, []) for n in names):
                    not_drawn.append(ns.split("::")[-1])
                continue
            w, h = ns_size[ns]
            gaps = any(n not in row and n in missing_any for n in names)
            row_h = max([ic["h"] for ic in row.values()] + [h if gaps else 0]) * scale
            sheet.text(24, sheet.y + min(row_h, 40) // 2 + 4, ns.split("::")[-1], fill=MUTED)
            x = 12 + label_col
            for n in names:
                if n in row:
                    sheet.icon(x, sheet.y, row[n])
                elif n in missing.get(ns, []):
                    sheet.parts.append(f'<rect x="{x + 0.5}" y="{sheet.y + 0.5}" width="{w * scale - 1}" '
                                       f'height="{h * scale - 1}" {DASHED}/>')
                x += col_w[n]
            sheet.width = max(sheet.width, x + 12)
            sheet.y += row_h + 10
        if not_drawn:
            sheet.text(24, sheet.y + 8, "not drawn yet: " + ", ".join(not_drawn), fill=MUTED)
            sheet.y += 18
        sheet.y += 12

    # Merge the section orders of all sizes: a section missing from earlier sizes goes after the
    # section that precedes it in its own header, not at the end.
    titles = []
    for ns in namespaces:
        prev = None
        for title in dict.fromkeys(ic["section"] for ic in icons if ic["ns"] == ns):
            if title not in titles:
                titles.insert(titles.index(prev) + 1 if prev else 0, title)
            prev = title

    for title in titles:
        members = [ic for ic in icons if ic["section"] == title]
        lines = {}
        for n in dict.fromkeys(ic["name"] for ic in members):
            lines.setdefault(variant(n), []).append(n)
        sheet.text(12, sheet.y + 14, title, size=13, bold=True)
        sheet.y += 30
        for base, names in sorted(lines.items(), key=lambda kv: kv[0] is None):   # sets first
            draw_line(base, names, members)
        sheet.y += 10
    return sheet.svg()


# --------------------------------------------------------------------------------------------------
# Main
# --------------------------------------------------------------------------------------------------

def collect(paths):
    """Expand directories to their headers, smallest icon size first (5x8, 8x8, 16x16)."""
    files = []
    for p in paths:
        p = Path(p)
        files += p.glob("*.h") if p.is_dir() else [p]

    def key(f):
        m = SIZE_RE.search(f.stem)
        return (int(m.group(1)) * int(m.group(2)) if m else float("inf"), f.name)
    return sorted(set(files), key=key)


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("paths", nargs="*", default=[REPO / "components" / "oli_icons"],
                    help="headers or directories (default: components/oli_icons/)")
    ap.add_argument("--out", default=REPO / "docs" / "preview.svg", help="SVG output path")
    ap.add_argument("--scale", type=int, default=6, help="screen pixels per icon pixel")
    ap.add_argument("--check", action="store_true", help="exit 1 if any errors are found")
    args = ap.parse_args()

    icons, sets = [], []
    for f in collect(args.paths):
        i, s = parse_header(f)
        icons += i
        sets += s
    if not icons:
        sys.exit("No icon arrays found.")
    missing = cross_checks(icons, sets)

    Path(args.out).parent.mkdir(parents=True, exist_ok=True)
    Path(args.out).write_text(render_svg(icons, sets, missing, args.scale))

    n_err = sum(len(x["errors"]) for x in icons + sets)
    n_warn = sum(len(ic["warnings"]) for ic in icons) + len(missing)
    for x in icons + sets:
        where = f'{x["file"]}:{x["line"]}'
        name = f'{x["ns"]}::{x["name"]}' if x["ns"] else x["name"]
        for msg in x["errors"]:
            print(f"{where}: error: {name}: {msg}")
        for msg in x.get("warnings", []):
            print(f"{where}: warning: {name}: {msg}")
    files = {ic["ns"]: ic["file"] for ic in icons}
    for ns, names in missing.items():
        print(f"{files[ns]}: warning: {ns}: {len(names)} icons not drawn yet: {', '.join(names)}")
    print(f"{len(icons)} icons, {len(sets)} sets, {n_err} errors, {n_warn} warnings -> {args.out}")
    if args.check and n_err:
        sys.exit(1)


if __name__ == "__main__":
    main()
