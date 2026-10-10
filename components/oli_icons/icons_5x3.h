#ifndef OLI_ICONS_5X3_H
#define OLI_ICONS_5X3_H

/**
 * -------------------------------------------------------------------------------------------------
 * GLYPHS 5x3 - namespace oli::icons_5x3
 *
 * Small UI glyphs, such as scrollbar and menu triangles. Same format as oli::icons_8x8: 1 bpp, one
 * byte per row, MSB = leftmost pixel.
 *
 *   namespace g = oli::icons_5x3;
 *   display.drawBitmap(x, y, g::triangleUp,   g::W, g::H, SSD1306_WHITE);  // 5 wide, 3 tall
 *   display.drawBitmap(x, y, g::triangleLeft, g::H, g::W, SSD1306_WHITE);  // 3 wide, 5 tall
 * -------------------------------------------------------------------------------------------------
 */

#include "icons_common.h"

namespace oli {
namespace icons_5x3 {

constexpr uint8_t W = 5;
constexpr uint8_t H = 3;

/**
 * -------------------------------------------------------------------------------------------------
 * Scroll
 * Up and down are W x H. Left and right lie on their side, so draw them H x W.
 * -------------------------------------------------------------------------------------------------
 */

static const uint8_t PROGMEM triangleUp[] = {
  0b00100000,  // ..X..
  0b01110000,  // .XXX.
  0b11111000   // XXXXX
};

static const uint8_t PROGMEM triangleDown[] = {
  0b11111000,  // XXXXX
  0b01110000,  // .XXX.
  0b00100000   // ..X..
};

static const uint8_t PROGMEM triangleLeft[] = {
  0b00100000,  // ..X
  0b01100000,  // .XX
  0b11100000,  // XXX
  0b01100000,  // .XX
  0b00100000   // ..X
};

static const uint8_t PROGMEM triangleRight[] = {
  0b10000000,  // X..
  0b11000000,  // XX.
  0b11100000,  // XXX
  0b11000000,  // XX.
  0b10000000   // X..
};
}  // namespace icons_5x3
}  // namespace oli

#endif
