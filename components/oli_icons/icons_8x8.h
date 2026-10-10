#ifndef OLI_ICONS_8X8_H
#define OLI_ICONS_8X8_H

/**
 * -------------------------------------------------------------------------------------------------
 * ICONS 8x8 - namespace oli::icons_8x8
 *
 * 1 bpp bitmaps, one byte per row, MSB = leftmost pixel.
 * Same format as Adafruit_GFX::drawBitmap() and ESPHome 1-bit images.
 *
 *   namespace ic = oli::icons_8x8;
 *   display.drawBitmap(x, y, ic::lock, ic::W, ic::H, SSD1306_WHITE);  // Arduino, Adafruit GFX
 *   oli::draw(it, x, y, ic::lock, ic::W, ic::H);                      // ESPHome display lambda
 *
 * Sets list levels lowest first. For a 0-100 value:
 *   oli::frame(ic::wifiSet, oli::levelIndex(percent, ic::wifiLevels))
 * -------------------------------------------------------------------------------------------------
 */

#include "icons_common.h"

namespace oli {
namespace icons_8x8 {

constexpr uint8_t W = 8;
constexpr uint8_t H = 8;

/**
 * -------------------------------------------------------------------------------------------------
 * Dialogs
 * -------------------------------------------------------------------------------------------------
 */

static const uint8_t PROGMEM info[] = {
  0b00011000,  // ...XX...
  0b00011000,  // ...XX...
  0b00000000,  // ........
  0b00111000,  // ..XXX...
  0b00011000,  // ...XX...
  0b00011000,  // ...XX...
  0b00011000,  // ...XX...
  0b00111100   // ..XXXX..
};

static const uint8_t PROGMEM warning[] = {
  0b00011000,  // ...XX...
  0b00011000,  // ...XX...
  0b00011000,  // ...XX...
  0b00011000,  // ...XX...
  0b00011000,  // ...XX...
  0b00011000,  // ...XX...
  0b00000000,  // ........
  0b00011000   // ...XX...
};

static const uint8_t PROGMEM error[] = {
  0b11000110,  // XX...XX.
  0b01101100,  // .XX.XX..
  0b00111000,  // ..XXX...
  0b00010000,  // ...X....
  0b00111000,  // ..XXX...
  0b01101100,  // .XX.XX..
  0b11000110,  // XX...XX.
  0b00000000   // ........
};

static const uint8_t PROGMEM question[] = {
  0b00111100,  // ..XXXX..
  0b01100110,  // .XX..XX.
  0b00000110,  // .....XX.
  0b00001100,  // ....XX..
  0b00011000,  // ...XX...
  0b00011000,  // ...XX...
  0b00000000,  // ........
  0b00011000   // ...XX...
};

/**
 * -------------------------------------------------------------------------------------------------
 * Power / navigation
 * -------------------------------------------------------------------------------------------------
 */

// Power / standby
static const uint8_t PROGMEM power[] = {
  0b00010000,  // ...X....
  0b01010100,  // .X.X.X..
  0b10010010,  // X..X..X.
  0b10010010,  // X..X..X.
  0b10000010,  // X.....X.
  0b10000010,  // X.....X.
  0b01000100,  // .X...X..
  0b00111000   // ..XXX...
};

// Sleep (crescent moon)
static const uint8_t PROGMEM sleep[] = {
  0b00011100,  // ...XXX..
  0b01110000,  // .XXX....
  0b01100000,  // .XX.....
  0b11100000,  // XXX.....
  0b11100000,  // XXX.....
  0b11110000,  // XXXX....
  0b01111110,  // .XXXXXX.
  0b00111100   // ..XXXX..
};

// Mains power / plugged in
static const uint8_t PROGMEM plug[] = {
  0b00101000,  // ..X.X...
  0b00101000,  // ..X.X...
  0b01111100,  // .XXXXX..
  0b01111100,  // .XXXXX..
  0b01111100,  // .XXXXX..
  0b00111000,  // ..XXX...
  0b00010000,  // ...X....
  0b00010000   // ...X....
};

static const uint8_t PROGMEM hourglass[] = {
  0b01111110,  // .XXXXXX.
  0b01111110,  // .XXXXXX.
  0b00111100,  // ..XXXX..
  0b00011000,  // ...XX...
  0b00011000,  // ...XX...
  0b00111100,  // ..XXXX..
  0b01111110,  // .XXXXXX.
  0b01111110   // .XXXXXX.
};

static const uint8_t PROGMEM home[] = {
  0b00010000,  // ...X....
  0b00111000,  // ..XXX...
  0b01111100,  // .XXXXX..
  0b11111110,  // XXXXXXX.
  0b01111100,  // .XXXXX..
  0b01111100,  // .XXXXX..
  0b01101100,  // .XX.XX..
  0b01101100   // .XX.XX..
};

// Rotate left / anticlockwise
static const uint8_t PROGMEM rotateL[] = {
  0b00010000,  // ...X....
  0b00100000,  // ..X.....
  0b01111100,  // .XXXXX..
  0b00100010,  // ..X...X.
  0b00010010,  // ...X..X.
  0b00000010,  // ......X.
  0b01000010,  // .X....X.
  0b00111100   // ..XXXX..
};

// Rotate right / clockwise
static const uint8_t PROGMEM rotateR[] = {
  0b00001000,  // ....X...
  0b00000100,  // .....X..
  0b00111110,  // ..XXXXX.
  0b01000100,  // .X...X..
  0b01001000,  // .X..X...
  0b01000000,  // .X......
  0b01000010,  // .X....X.
  0b00111100   // ..XXXX..
};

// Swap left / anticlockwise (two circular arrows)
static const uint8_t PROGMEM swapL[] = {
  0b00011100,  // ...XXX..
  0b10100010,  // X.X...X.
  0b11000000,  // XX......
  0b11100000,  // XXX.....
  0b00000111,  // .....XXX
  0b00000011,  // ......XX
  0b01000101,  // .X...X.X
  0b00111000   // ..XXX...
};

// Swap right / clockwise (two circular arrows)
static const uint8_t PROGMEM swapR[] = {
  0b01111000,  // .XXXX...
  0b10000101,  // X....X.X
  0b00000011,  // ......XX
  0b00000111,  // .....XXX
  0b11100000,  // XXX.....
  0b11000001,  // XX.....X
  0b10100010,  // X.X...X.
  0b00011100   // ...XXX..
};

static const uint8_t PROGMEM plus[] = {
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b11111110,  // XXXXXXX.
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b00000000   // ........
};

static const uint8_t PROGMEM minus[] = {
  0b00000000,  // ........
  0b00000000,  // ........
  0b00000000,  // ........
  0b11111110,  // XXXXXXX.
  0b00000000,  // ........
  0b00000000,  // ........
  0b00000000,  // ........
  0b00000000   // ........
};

static const uint8_t PROGMEM tick[] = {
  0b00000000,  // ........
  0b00000010,  // ......X.
  0b00000100,  // .....X..
  0b10001000,  // X...X...
  0b01010000,  // .X.X....
  0b00100000,  // ..X.....
  0b00000000,  // ........
  0b00000000   // ........
};

static const uint8_t PROGMEM cross[] = {
  0b10000010,  // X.....X.
  0b01000100,  // .X...X..
  0b00101000,  // ..X.X...
  0b00010000,  // ...X....
  0b00101000,  // ..X.X...
  0b01000100,  // .X...X..
  0b10000010,  // X.....X.
  0b00000000   // ........
};

static const uint8_t PROGMEM checkboxTicked[] = {
  0b11111110,  // XXXXXXX.
  0b10000010,  // X.....X.
  0b10001010,  // X...X.X.
  0b11010010,  // XX.X..X.
  0b10100010,  // X.X...X.
  0b10000010,  // X.....X.
  0b11111110,  // XXXXXXX.
  0b00000000   // ........
};

static const uint8_t PROGMEM checkboxEmpty[] = {
  0b11111110,  // XXXXXXX.
  0b10000010,  // X.....X.
  0b10000010,  // X.....X.
  0b10000010,  // X.....X.
  0b10000010,  // X.....X.
  0b10000010,  // X.....X.
  0b11111110,  // XXXXXXX.
  0b00000000   // ........
};

/**
 * -------------------------------------------------------------------------------------------------
 * Battery
 * battery0 (empty) ... battery5 (full)
 * -------------------------------------------------------------------------------------------------
 */

static const uint8_t PROGMEM battery0[] = {
  0b00000000,  // ........
  0b11111110,  // XXXXXXX.
  0b10000010,  // X.....X.
  0b10000011,  // X.....XX
  0b10000011,  // X.....XX
  0b10000010,  // X.....X.
  0b11111110,  // XXXXXXX.
  0b00000000   // ........
};

static const uint8_t PROGMEM battery1[] = {
  0b00000000,  // ........
  0b11111110,  // XXXXXXX.
  0b11000010,  // XX....X.
  0b11000011,  // XX....XX
  0b11000011,  // XX....XX
  0b11000010,  // XX....X.
  0b11111110,  // XXXXXXX.
  0b00000000   // ........
};

static const uint8_t PROGMEM battery2[] = {
  0b00000000,  // ........
  0b11111110,  // XXXXXXX.
  0b11100010,  // XXX...X.
  0b11100011,  // XXX...XX
  0b11100011,  // XXX...XX
  0b11100010,  // XXX...X.
  0b11111110,  // XXXXXXX.
  0b00000000   // ........
};

static const uint8_t PROGMEM battery3[] = {
  0b00000000,  // ........
  0b11111110,  // XXXXXXX.
  0b11110010,  // XXXX..X.
  0b11110011,  // XXXX..XX
  0b11110011,  // XXXX..XX
  0b11110010,  // XXXX..X.
  0b11111110,  // XXXXXXX.
  0b00000000   // ........
};

static const uint8_t PROGMEM battery4[] = {
  0b00000000,  // ........
  0b11111110,  // XXXXXXX.
  0b11111010,  // XXXXX.X.
  0b11111011,  // XXXXX.XX
  0b11111011,  // XXXXX.XX
  0b11111010,  // XXXXX.X.
  0b11111110,  // XXXXXXX.
  0b00000000   // ........
};

static const uint8_t PROGMEM battery5[] = {
  0b00000000,  // ........
  0b11111110,  // XXXXXXX.
  0b11111110,  // XXXXXXX.
  0b11111111,  // XXXXXXXX
  0b11111111,  // XXXXXXXX
  0b11111110,  // XXXXXXX.
  0b11111110,  // XXXXXXX.
  0b00000000   // ........
};

static const uint8_t PROGMEM batteryCharging[] = {
  0b00000000,  // ........
  0b11111110,  // XXXXXXX.
  0b10001010,  // X...X.X.
  0b10011011,  // X..XX.XX
  0b10110011,  // X.XX..XX
  0b10100010,  // X.X...X.
  0b11111110,  // XXXXXXX.
  0b00000000   // ........
};

static const uint8_t PROGMEM batteryError[] = {
  0b00000000,  // ........
  0b11010110,  // XX.X.XX.
  0b10010010,  // X..X..X.
  0b10010011,  // X..X..XX
  0b10010011,  // X..X..XX
  0b10000010,  // X.....X.
  0b11010110,  // XX.X.XX.
  0b00000000   // ........
};

static const uint8_t* const batterySet[] PROGMEM = {
  battery0, battery1, battery2, battery3, battery4, battery5
};
constexpr uint8_t batteryLevels = sizeof(batterySet) / sizeof(batterySet[0]);

/**
 * -------------------------------------------------------------------------------------------------
 * Signal strength
 * wifi0 (weakest) ... wifi3 (strongest)
 * -------------------------------------------------------------------------------------------------
 */

static const uint8_t PROGMEM wifi0[] = {
  0b00000000,  // ........
  0b00000000,  // ........
  0b00000000,  // ........
  0b00000000,  // ........
  0b00000000,  // ........
  0b00000000,  // ........
  0b00010000,  // ...X....
  0b00000000   // ........
};

static const uint8_t PROGMEM wifi1[] = {
  0b00000000,  // ........
  0b00000000,  // ........
  0b00000000,  // ........
  0b00000000,  // ........
  0b00111000,  // ..XXX...
  0b00000000,  // ........
  0b00010000,  // ...X....
  0b00000000   // ........
};

static const uint8_t PROGMEM wifi2[] = {
  0b00000000,  // ........
  0b00000000,  // ........
  0b01111100,  // .XXXXX..
  0b00000000,  // ........
  0b00111000,  // ..XXX...
  0b00000000,  // ........
  0b00010000,  // ...X....
  0b00000000   // ........
};

static const uint8_t PROGMEM wifi3[] = {
  0b11111110,  // XXXXXXX.
  0b00000000,  // ........
  0b01111100,  // .XXXXX..
  0b00000000,  // ........
  0b00111000,  // ..XXX...
  0b00000000,  // ........
  0b00010000,  // ...X....
  0b00000000   // ........
};

static const uint8_t PROGMEM wifiDisconnected[] = {
  0b01000100,  // .X...X..
  0b00101000,  // ..X.X...
  0b00010000,  // ...X....
  0b00101000,  // ..X.X...
  0b01000100,  // .X...X..
  0b00000000,  // ........
  0b00010000,  // ...X....
  0b00000000   // ........
};

static const uint8_t PROGMEM wifiOff[] = {
  0b01000000,  // .X......
  0b00100000,  // ..X.....
  0b00010000,  // ...X....
  0b00001000,  // ....X...
  0b00000100,  // .....X..
  0b00000000,  // ........
  0b00010000,  // ...X....
  0b00000000   // ........
};

static const uint8_t* const wifiSet[] PROGMEM = {
  wifi0, wifi1, wifi2, wifi3
};
constexpr uint8_t wifiLevels = sizeof(wifiSet) / sizeof(wifiSet[0]);

/**
 * -------------------------------------------------------------------------------------------------
 * Tank / capacity
 * tank0 (empty) ... tank7 (full)
 * -------------------------------------------------------------------------------------------------
 */

static const uint8_t PROGMEM tank0[] = {
  0b11000011,  // XX....XX
  0b01000010,  // .X....X.
  0b01000010,  // .X....X.
  0b01000010,  // .X....X.
  0b01000010,  // .X....X.
  0b01000010,  // .X....X.
  0b01000010,  // .X....X.
  0b01111110   // .XXXXXX.
};

static const uint8_t PROGMEM tank1[] = {
  0b11000011,  // XX....XX
  0b01000010,  // .X....X.
  0b01000010,  // .X....X.
  0b01000010,  // .X....X.
  0b01000010,  // .X....X.
  0b01000010,  // .X....X.
  0b01111110,  // .XXXXXX.
  0b01111110   // .XXXXXX.
};

static const uint8_t PROGMEM tank2[] = {
  0b11000011,  // XX....XX
  0b01000010,  // .X....X.
  0b01000010,  // .X....X.
  0b01000010,  // .X....X.
  0b01000010,  // .X....X.
  0b01111110,  // .XXXXXX.
  0b01111110,  // .XXXXXX.
  0b01111110   // .XXXXXX.
};

static const uint8_t PROGMEM tank3[] = {
  0b11000011,  // XX....XX
  0b01000010,  // .X....X.
  0b01000010,  // .X....X.
  0b01000010,  // .X....X.
  0b01111110,  // .XXXXXX.
  0b01111110,  // .XXXXXX.
  0b01111110,  // .XXXXXX.
  0b01111110   // .XXXXXX.
};

static const uint8_t PROGMEM tank4[] = {
  0b11000011,  // XX....XX
  0b01000010,  // .X....X.
  0b01000010,  // .X....X.
  0b01111110,  // .XXXXXX.
  0b01111110,  // .XXXXXX.
  0b01111110,  // .XXXXXX.
  0b01111110,  // .XXXXXX.
  0b01111110   // .XXXXXX.
};

static const uint8_t PROGMEM tank5[] = {
  0b11000011,  // XX....XX
  0b01000010,  // .X....X.
  0b01111110,  // .XXXXXX.
  0b01111110,  // .XXXXXX.
  0b01111110,  // .XXXXXX.
  0b01111110,  // .XXXXXX.
  0b01111110,  // .XXXXXX.
  0b01111110   // .XXXXXX.
};

static const uint8_t PROGMEM tank6[] = {
  0b11000011,  // XX....XX
  0b01111110,  // .XXXXXX.
  0b01111110,  // .XXXXXX.
  0b01111110,  // .XXXXXX.
  0b01111110,  // .XXXXXX.
  0b01111110,  // .XXXXXX.
  0b01111110,  // .XXXXXX.
  0b01111110   // .XXXXXX.
};

static const uint8_t PROGMEM tank7[] = {
  0b11111111,  // XXXXXXXX
  0b01111110,  // .XXXXXX.
  0b01111110,  // .XXXXXX.
  0b01111110,  // .XXXXXX.
  0b01111110,  // .XXXXXX.
  0b01111110,  // .XXXXXX.
  0b01111110,  // .XXXXXX.
  0b01111110   // .XXXXXX.
};

static const uint8_t PROGMEM tankError[] = {
  0b11011011,  // XX.XX.XX
  0b01011010,  // .X.XX.X.
  0b01011010,  // .X.XX.X.
  0b01011010,  // .X.XX.X.
  0b01000010,  // .X....X.
  0b01011010,  // .X.XX.X.
  0b01000010,  // .X....X.
  0b01111110   // .XXXXXX.
};

static const uint8_t* const tankSet[] PROGMEM = {
  tank0, tank1, tank2, tank3, tank4, tank5, tank6, tank7
};
constexpr uint8_t tankLevels = sizeof(tankSet) / sizeof(tankSet[0]);

/**
 * -------------------------------------------------------------------------------------------------
 * Network
 * -------------------------------------------------------------------------------------------------
 */

static const uint8_t PROGMEM badge5G[] = {
  0b11101111,  // XXX.XXXX
  0b10001000,  // X...X...
  0b10001000,  // X...X...
  0b11001000,  // XX..X...
  0b00101011,  // ..X.X.XX
  0b00101001,  // ..X.X..X
  0b00101001,  // ..X.X..X
  0b11001111   // XX..XXXX
};

static const uint8_t PROGMEM badge4G[] = {
  0b10101111,  // X.X.XXXX
  0b10101000,  // X.X.X...
  0b10101000,  // X.X.X...
  0b11101000,  // XXX.X...
  0b00101011,  // ..X.X.XX
  0b00101001,  // ..X.X..X
  0b00101001,  // ..X.X..X
  0b00101111   // ..X.XXXX
};

static const uint8_t PROGMEM badge3G[] = {
  0b11101111,  // XXX.XXXX
  0b00101000,  // ..X.X...
  0b00101000,  // ..X.X...
  0b11101000,  // XXX.X...
  0b00101011,  // ..X.X.XX
  0b00101001,  // ..X.X..X
  0b00101001,  // ..X.X..X
  0b11101111   // XXX.XXXX
};

static const uint8_t PROGMEM badge2G[] = {
  0b11101111,  // XXX.XXXX
  0b00101000,  // ..X.X...
  0b00101000,  // ..X.X...
  0b11101000,  // XXX.X...
  0b10001011,  // X...X.XX
  0b10001001,  // X...X..X
  0b10001001,  // X...X..X
  0b11101111   // XXX.XXXX
};

static const uint8_t PROGMEM badgeLoRa[] = {
  0b10001110,  // X...XXX.
  0b10001010,  // X...X.X.
  0b11101110,  // XXX.XXX.
  0b00000000,  // ........
  0b11001110,  // XX..XXX.
  0b10101010,  // X.X.X.X.
  0b11001110,  // XX..XXX.
  0b10101010   // X.X.X.X.
};

static const uint8_t PROGMEM badgeWifi[] = {
  0b10001010,  // X...X.X.
  0b10101010,  // X.X.X.X.
  0b11111010,  // XXXXX.X.
  0b00000000,  // ........
  0b00011010,  // ...XX.X.
  0b00010010,  // ...X..X.
  0b11011010,  // XX.XX.X.
  0b00010010   // ...X..X.
};

static const uint8_t PROGMEM bluetooth[] = {
  0b00011000,  // ...XX...
  0b01010100,  // .X.X.X..
  0b00110010,  // ..XX..X.
  0b00011100,  // ...XXX..
  0b00110010,  // ..XX..X.
  0b01010100,  // .X.X.X..
  0b00011000,  // ...XX...
  0b00000000   // ........
};

/**
 * -------------------------------------------------------------------------------------------------
 * Security / connection
 * -------------------------------------------------------------------------------------------------
 */

static const uint8_t PROGMEM lock[] = {
  0b00111000,  // ..XXX...
  0b01000100,  // .X...X..
  0b01000100,  // .X...X..
  0b01000100,  // .X...X..
  0b11111110,  // XXXXXXX.
  0b11101110,  // XXX.XXX.
  0b11101110,  // XXX.XXX.
  0b11111110   // XXXXXXX.
};

static const uint8_t PROGMEM unlock[] = {
  0b00111000,  // ..XXX...
  0b01000100,  // .X...X..
  0b01000000,  // .X......
  0b01000000,  // .X......
  0b11111110,  // XXXXXXX.
  0b11101110,  // XXX.XXX.
  0b11101110,  // XXX.XXX.
  0b11111110   // XXXXXXX.
};

static const uint8_t PROGMEM key[] = {
  0b00000000,  // ........
  0b01100000,  // .XX.....
  0b10010000,  // X..X....
  0b10011111,  // X..XXXXX
  0b10010101,  // X..X.X.X
  0b01100000,  // .XX.....
  0b00000000,  // ........
  0b00000000   // ........
};

static const uint8_t PROGMEM link[] = {
  0b11110000,  // XXXX....
  0b10010000,  // X..X....
  0b10011110,  // X..XXXX.
  0b10010010,  // X..X..X.
  0b11110010,  // XXXX..X.
  0b00010010,  // ...X..X.
  0b00011110,  // ...XXXX.
  0b00000000   // ........
};

// Airplane mode
static const uint8_t PROGMEM airplane[] = {
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b01111100,  // .XXXXX..
  0b11111110,  // XXXXXXX.
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b00111000,  // ..XXX...
  0b01111100   // .XXXXX..
};

/**
 * -------------------------------------------------------------------------------------------------
 * Other
 * -------------------------------------------------------------------------------------------------
 */

static const uint8_t PROGMEM plant[] = {
  0b00001100,  // ....XX..
  0b00011100,  // ...XXX..
  0b01011000,  // .X.XX...
  0b00110000,  // ..XX....
  0b00010000,  // ...X....
  0b01111100,  // .XXXXX..
  0b00111000,  // ..XXX...
  0b00111000   // ..XXX...
};

static const uint8_t PROGMEM waterDrop[] = {
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b00111000,  // ..XXX...
  0b00111000,  // ..XXX...
  0b01111100,  // .XXXXX..
  0b01111100,  // .XXXXX..
  0b01111100,  // .XXXXX..
  0b00111000   // ..XXX...
};

static const uint8_t PROGMEM clock[] = {
  0b00111000,  // ..XXX...
  0b01000100,  // .X...X..
  0b10010010,  // X..X..X.
  0b10010010,  // X..X..X.
  0b10100010,  // X.X...X.
  0b10000010,  // X.....X.
  0b01000100,  // .X...X..
  0b00111000   // ..XXX...
};

static const uint8_t PROGMEM faucet[] = {
  0b00010000,  // ...X....
  0b00111000,  // ..XXX...
  0b00010010,  // ...X..X.
  0b00111110,  // ..XXXXX.
  0b01111110,  // .XXXXXX.
  0b01100010,  // .XX...X.
  0b01100000,  // .XX.....
  0b01100000   // .XX.....
};

static const uint8_t PROGMEM cup[] = {
  0b01111110,  // .XXXXXX.
  0b01111110,  // .XXXXXX.
  0b01111110,  // .XXXXXX.
  0b00111100,  // ..XXXX..
  0b00011000,  // ...XX...
  0b00011000,  // ...XX...
  0b00011000,  // ...XX...
  0b00111100   // ..XXXX..
};

static const uint8_t PROGMEM sound[] = {
  0b00000000,  // ........
  0b00010010,  // ...X..X.
  0b00110100,  // ..XX.X..
  0b11110000,  // XXXX....
  0b11110110,  // XXXX.XX.
  0b11110000,  // XXXX....
  0b00110100,  // ..XX.X..
  0b00010010   // ...X..X.
};

static const uint8_t PROGMEM music[] = {
  0b01111100,  // .XXXXX..
  0b01111100,  // .XXXXX..
  0b01000100,  // .X...X..
  0b01000100,  // .X...X..
  0b01000100,  // .X...X..
  0b01110111,  // .XXX.XXX
  0b01110111,  // .XXX.XXX
  0b01110111   // .XXX.XXX
};

static const uint8_t PROGMEM book[] = {
  0b11000011,  // XX....XX
  0b10100101,  // X.X..X.X
  0b10011001,  // X..XX..X
  0b10011001,  // X..XX..X
  0b10011001,  // X..XX..X
  0b10011001,  // X..XX..X
  0b01011010,  // .X.XX.X.
  0b00111100   // ..XXXX..
};

static const uint8_t PROGMEM flag[] = {
  0b01000000,  // .X......
  0b01111100,  // .XXXXX..
  0b01000010,  // .X....X.
  0b01111100,  // .XXXXX..
  0b01000000,  // .X......
  0b01000000,  // .X......
  0b01000000,  // .X......
  0b01000000   // .X......
};

static const uint8_t PROGMEM brightness[] = {
  0b00010000,  // ...X....
  0b01010100,  // .X.X.X..
  0b00111000,  // ..XXX...
  0b11111110,  // XXXXXXX.
  0b00111000,  // ..XXX...
  0b01010100,  // .X.X.X..
  0b00010000,  // ...X....
  0b00000000   // ........
};

static const uint8_t PROGMEM contrast[] = {
  0b00111100,  // ..XXXX..
  0b01001110,  // .X..XXX.
  0b10001111,  // X...XXXX
  0b10001111,  // X...XXXX
  0b10001111,  // X...XXXX
  0b10001111,  // X...XXXX
  0b01001110,  // .X..XXX.
  0b00111100   // ..XXXX..
};

// Material "grain"
static const uint8_t PROGMEM pattern[] = {
  0b11001100,  // XX..XX..
  0b11001100,  // XX..XX..
  0b00000000,  // ........
  0b00110011,  // ..XX..XX
  0b00110011,  // ..XX..XX
  0b00000000,  // ........
  0b11001100,  // XX..XX..
  0b11001100   // XX..XX..
};

static const uint8_t PROGMEM colour[] = {
  0b00111100,  // ..XXXX..
  0b01101110,  // .XX.XXX.
  0b10111011,  // X.XXX.XX
  0b11111111,  // XXXXXXXX
  0b10111110,  // X.XXXXX.
  0b11111100,  // XXXXXX..
  0b01111000,  // .XXXX...
  0b00110000   // ..XX....
};

static const uint8_t PROGMEM bulbOn[] = {
  0b00111000,  // ..XXX...
  0b01000100,  // .X...X..
  0b10000010,  // X.....X.
  0b10000010,  // X.....X.
  0b10000010,  // X.....X.
  0b01000100,  // .X...X..
  0b00111000,  // ..XXX...
  0b00111000   // ..XXX...
};

// Bulb with a line through it, like Home Assistant's lightbulb-off-outline
static const uint8_t PROGMEM bulbOff[] = {
  0b00111000,  // ..XXX...
  0b01000100,  // .X...X..
  0b10100010,  // X.X...X.
  0b10010010,  // X..X..X.
  0b10001010,  // X...X.X.
  0b01000100,  // .X...X..
  0b00111000,  // ..XXX...
  0b00111000   // ..XXX...
};

static const uint8_t PROGMEM cat[] = {
  0b10000010,  // X.....X.
  0b11000110,  // XX...XX.
  0b11111110,  // XXXXXXX.
  0b11010110,  // XX.X.XX.
  0b11111110,  // XXXXXXX.
  0b11111110,  // XXXXXXX.
  0b01111100,  // .XXXXX..
  0b00111000   // ..XXX...
};

// Blocked / not allowed
static const uint8_t PROGMEM blocked[] = {
  0b00111100,  // ..XXXX..
  0b01000010,  // .X....X.
  0b10100001,  // X.X....X
  0b10010001,  // X..X...X
  0b10001001,  // X...X..X
  0b10000101,  // X....X.X
  0b01000010,  // .X....X.
  0b00111100   // ..XXXX..
};

static const uint8_t PROGMEM doorOpen[] = {
  0b01111100,  // .XXXXX..
  0b01100100,  // .XX..X..
  0b01110100,  // .XXX.X..
  0b01110100,  // .XXX.X..
  0b01110100,  // .XXX.X..
  0b01110100,  // .XXX.X..
  0b01100100,  // .XX..X..
  0b11111110   // XXXXXXX.
};

static const uint8_t PROGMEM doorClosed[] = {
  0b01111100,  // .XXXXX..
  0b01111100,  // .XXXXX..
  0b01111100,  // .XXXXX..
  0b01111100,  // .XXXXX..
  0b01110100,  // .XXX.X..
  0b01111100,  // .XXXXX..
  0b01111100,  // .XXXXX..
  0b11111110   // XXXXXXX.
};

/**
 * -------------------------------------------------------------------------------------------------
 * Arrows (small)
 * -------------------------------------------------------------------------------------------------
 */

static const uint8_t PROGMEM arrowUpSmall[] = {
  0b00010000,  // ...X....
  0b00111000,  // ..XXX...
  0b01010100,  // .X.X.X..
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b00000000,  // ........
  0b00000000,  // ........
  0b00000000   // ........
};

static const uint8_t PROGMEM arrowDownSmall[] = {
  0b00000000,  // ........
  0b00000000,  // ........
  0b00000000,  // ........
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b01010100,  // .X.X.X..
  0b00111000,  // ..XXX...
  0b00010000   // ...X....
};

static const uint8_t PROGMEM arrowLeftSmall[] = {
  0b00000000,  // ........
  0b00100000,  // ..X.....
  0b01000000,  // .X......
  0b11111000,  // XXXXX...
  0b01000000,  // .X......
  0b00100000,  // ..X.....
  0b00000000,  // ........
  0b00000000   // ........
};

static const uint8_t PROGMEM arrowRightSmall[] = {
  0b00000000,  // ........
  0b00000100,  // .....X..
  0b00000010,  // ......X.
  0b00011111,  // ...XXXXX
  0b00000010,  // ......X.
  0b00000100,  // .....X..
  0b00000000,  // ........
  0b00000000   // ........
};

static const uint8_t PROGMEM arrowReturnSmall[] = {
  0b00010000,  // ...X....
  0b00100000,  // ..X.....
  0b01111110,  // .XXXXXX.
  0b00100010,  // ..X...X.
  0b00010010,  // ...X..X.
  0b00000010,  // ......X.
  0b00000010,  // ......X.
  0b00000000   // ........
};

static const uint8_t PROGMEM arrowUpLongSmall[] = {
  0b00010000,  // ...X....
  0b00111000,  // ..XXX...
  0b01010100,  // .X.X.X..
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b00010000   // ...X....
};

static const uint8_t PROGMEM arrowDownLongSmall[] = {
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b01010100,  // .X.X.X..
  0b00111000,  // ..XXX...
  0b00010000   // ...X....
};

/**
 * -------------------------------------------------------------------------------------------------
 * Arrows (small, solid)
 * -------------------------------------------------------------------------------------------------
 */

static const uint8_t PROGMEM arrowUpSmallSolid[] = {
  0b00010000,  // ...X....
  0b00111000,  // ..XXX...
  0b01111100,  // .XXXXX..
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b00000000,  // ........
  0b00000000,  // ........
  0b00000000   // ........
};

static const uint8_t PROGMEM arrowDownSmallSolid[] = {
  0b00000000,  // ........
  0b00000000,  // ........
  0b00000000,  // ........
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b01111100,  // .XXXXX..
  0b00111000,  // ..XXX...
  0b00010000   // ...X....
};

static const uint8_t PROGMEM arrowLeftSmallSolid[] = {
  0b00000000,  // ........
  0b00100000,  // ..X.....
  0b01100000,  // .XX.....
  0b11111000,  // XXXXX...
  0b01100000,  // .XX.....
  0b00100000,  // ..X.....
  0b00000000,  // ........
  0b00000000   // ........
};

static const uint8_t PROGMEM arrowRightSmallSolid[] = {
  0b00000000,  // ........
  0b00000100,  // .....X..
  0b00000110,  // .....XX.
  0b00011111,  // ...XXXXX
  0b00000110,  // .....XX.
  0b00000100,  // .....X..
  0b00000000,  // ........
  0b00000000   // ........
};

static const uint8_t PROGMEM arrowReturnSmallSolid[] = {
  0b00010000,  // ...X....
  0b00110000,  // ..XX....
  0b01111110,  // .XXXXXX.
  0b00110010,  // ..XX..X.
  0b00010010,  // ...X..X.
  0b00000010,  // ......X.
  0b00000010,  // ......X.
  0b00000010   // ......X.
};

static const uint8_t PROGMEM arrowUpLongSmallSolid[] = {
  0b00010000,  // ...X....
  0b00111000,  // ..XXX...
  0b01111100,  // .XXXXX..
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b00010000   // ...X....
};

static const uint8_t PROGMEM arrowDownLongSmallSolid[] = {
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b01111100,  // .XXXXX..
  0b00111000,  // ..XXX...
  0b00010000   // ...X....
};

/**
 * -------------------------------------------------------------------------------------------------
 * Arrows (large)
 * -------------------------------------------------------------------------------------------------
 */

static const uint8_t PROGMEM arrowUpLarge[] = {
  0b00010000,  // ...X....
  0b00111000,  // ..XXX...
  0b01010100,  // .X.X.X..
  0b10010010,  // X..X..X.
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b00010000   // ...X....
};

static const uint8_t PROGMEM arrowDownLarge[] = {
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b10010010,  // X..X..X.
  0b01010100,  // .X.X.X..
  0b00111000,  // ..XXX...
  0b00010000   // ...X....
};

static const uint8_t PROGMEM arrowLeftLarge[] = {
  0b00010000,  // ...X....
  0b00100000,  // ..X.....
  0b01000000,  // .X......
  0b11111111,  // XXXXXXXX
  0b01000000,  // .X......
  0b00100000,  // ..X.....
  0b00010000,  // ...X....
  0b00000000   // ........
};

static const uint8_t PROGMEM arrowRightLarge[] = {
  0b00001000,  // ....X...
  0b00000100,  // .....X..
  0b00000010,  // ......X.
  0b11111111,  // XXXXXXXX
  0b00000010,  // ......X.
  0b00000100,  // .....X..
  0b00001000,  // ....X...
  0b00000000   // ........
};

static const uint8_t PROGMEM arrowReturnLarge[] = {
  0b00010000,  // ...X....
  0b00100000,  // ..X.....
  0b01000000,  // .X......
  0b11111110,  // XXXXXXX.
  0b01000010,  // .X....X.
  0b00100010,  // ..X...X.
  0b00010010,  // ...X..X.
  0b00000010   // ......X.
};

/**
 * -------------------------------------------------------------------------------------------------
 * Arrows (large, solid)
 * -------------------------------------------------------------------------------------------------
 */

static const uint8_t PROGMEM arrowUpLargeSolid[] = {
  0b00010000,  // ...X....
  0b00111000,  // ..XXX...
  0b01111100,  // .XXXXX..
  0b11111110,  // XXXXXXX.
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b00010000   // ...X....
};

static const uint8_t PROGMEM arrowDownLargeSolid[] = {
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b00010000,  // ...X....
  0b11111110,  // XXXXXXX.
  0b01111100,  // .XXXXX..
  0b00111000,  // ..XXX...
  0b00010000   // ...X....
};

static const uint8_t PROGMEM arrowLeftLargeSolid[] = {
  0b00010000,  // ...X....
  0b00110000,  // ..XX....
  0b01110000,  // .XXX....
  0b11111111,  // XXXXXXXX
  0b01110000,  // .XXX....
  0b00110000,  // ..XX....
  0b00010000,  // ...X....
  0b00000000   // ........
};

static const uint8_t PROGMEM arrowRightLargeSolid[] = {
  0b00001000,  // ....X...
  0b00001100,  // ....XX..
  0b00001110,  // ....XXX.
  0b11111111,  // XXXXXXXX
  0b00001110,  // ....XXX.
  0b00001100,  // ....XX..
  0b00001000,  // ....X...
  0b00000000   // ........
};

static const uint8_t PROGMEM arrowReturnLargeSolid[] = {
  0b00010000,  // ...X....
  0b00110000,  // ..XX....
  0b01110000,  // .XXX....
  0b11111110,  // XXXXXXX.
  0b01110010,  // .XXX..X.
  0b00110010,  // ..XX..X.
  0b00010010,  // ...X..X.
  0b00000010   // ......X.
};
}  // namespace icons_8x8
}  // namespace oli

#endif
