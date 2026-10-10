#ifndef OLI_ICONS_ESPHOME_H
#define OLI_ICONS_ESPHOME_H

/**
 * -------------------------------------------------------------------------------------------------
 * ESPHOME DRAW HELPER
 *
 * Draws an icon from a display lambda. ESPHome includes this header automatically once the
 * oli_icons component is loaded. Arduino code doesn't use it (call drawBitmap() instead).
 *
 *   namespace ic = oli::icons_8x8;
 *   oli::draw(it, 0, 0, ic::wifi3, ic::W, ic::H);
 *   oli::draw(it, 0, 0, ic::wifi3, ic::W, ic::H, COLOR_OFF);  // dark icon on a lit area
 *   oli::draw(it, 0, 0, oli::frame(ic::batterySet, oli::levelIndex(pct, ic::batteryLevels)),
 *             ic::W, ic::H);
 *
 * Only the icon's "on" pixels are drawn. Clear the area first with
 * it.filled_rectangle(x, y, w, h, COLOR_OFF) if the icon replaces another one.
 * -------------------------------------------------------------------------------------------------
 */

#include "esphome/components/display/display.h"
#include "icons_common.h"

namespace oli {

inline void draw(esphome::display::Display &it, int x, int y, const uint8_t *bitmap, int w, int h,
                 esphome::Color color = esphome::display::COLOR_ON) {
  const int bytes_per_row = (w + 7) / 8;
  for (int row = 0; row < h; row++) {
    for (int col = 0; col < w; col++) {
      if (OLI_READ_BYTE(bitmap + row * bytes_per_row + col / 8) & (0x80 >> (col % 8)))
        it.draw_pixel_at(x + col, y + row, color);
    }
  }
}

}  // namespace oli

#endif
