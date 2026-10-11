#ifndef OLI_ICONS_5X8_H
#define OLI_ICONS_5X8_H

/**
 * -------------------------------------------------------------------------------------------------
 * CHARACTER LCD GLYPHS 5x8 - namespace oli::icons_5x8
 *
 * Custom characters for HD44780 LCDs (LCD1602, LCD2004): 8 rows, low 5 bits = pixels.
 * Load up to 8 at a time into CGRAM slots 0-7, then print them as "\x08".."\x0F".
 *
 *   namespace lc = oli::icons_5x8;
 *   oli::loadChar(lcd, 0, lc::lock);                                               // print "\x08"
 *   oli::loadChar(lcd, 1, oli::frame(lc::batterySet, oli::levelIndex(percent, lc::batteryLevels)));
 * -------------------------------------------------------------------------------------------------
 */

#include "icons_common.h"

namespace oli {

/**
 * Copy a glyph into CGRAM slot 0-7. Works with any LCD class that has createChar(uint8_t, uint8_t[]).
 */
template <typename Lcd>
inline void loadChar(Lcd& lcd, uint8_t slot, const uint8_t* glyph) {
  uint8_t rows[8];
  for (uint8_t i = 0; i < 8; i++) rows[i] = OLI_READ_BYTE(glyph + i);
  lcd.createChar(slot, rows);
}

namespace icons_5x8 {

constexpr uint8_t W = 5;
constexpr uint8_t H = 8;

/**
 * -------------------------------------------------------------------------------------------------
 * Dialogs
 * -------------------------------------------------------------------------------------------------
 */

static const uint8_t PROGMEM info[] = {
  0b00000,  // .....
  0b00100,  // ..X..
  0b00000,  // .....
  0b01100,  // .XX..
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b01110,  // .XXX.
  0b00000   // .....
};

static const uint8_t PROGMEM warning[] = {
  0b00000,  // .....
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b00000,  // .....
  0b00100,  // ..X..
  0b00000   // .....
};

static const uint8_t PROGMEM error[] = {
  0b00000,  // .....
  0b10001,  // X...X
  0b01010,  // .X.X.
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b01010,  // .X.X.
  0b10001,  // X...X
  0b00000   // .....
};

static const uint8_t PROGMEM question[] = {
  0b00000,  // .....
  0b01110,  // .XXX.
  0b00010,  // ...X.
  0b00110,  // ..XX.
  0b00100,  // ..X..
  0b00000,  // .....
  0b00100,  // ..X..
  0b00000   // .....
};

/**
 * -------------------------------------------------------------------------------------------------
 * Dialogs (inverted)
 * -------------------------------------------------------------------------------------------------
 */

static const uint8_t PROGMEM infoInv[] = {
  0b11111,  // XXXXX
  0b11011,  // XX.XX
  0b11111,  // XXXXX
  0b10011,  // X..XX
  0b11011,  // XX.XX
  0b11011,  // XX.XX
  0b10001,  // X...X
  0b11111   // XXXXX
};

static const uint8_t PROGMEM warningInv[] = {
  0b11111,  // XXXXX
  0b11011,  // XX.XX
  0b11011,  // XX.XX
  0b11011,  // XX.XX
  0b11011,  // XX.XX
  0b11111,  // XXXXX
  0b11011,  // XX.XX
  0b11111   // XXXXX
};

static const uint8_t PROGMEM errorInv[] = {
  0b11111,  // XXXXX
  0b01110,  // .XXX.
  0b10101,  // X.X.X
  0b11011,  // XX.XX
  0b11011,  // XX.XX
  0b10101,  // X.X.X
  0b01110,  // .XXX.
  0b11111   // XXXXX
};

static const uint8_t PROGMEM questionInv[] = {
  0b11111,  // XXXXX
  0b10001,  // X...X
  0b11101,  // XXX.X
  0b11001,  // XX..X
  0b11011,  // XX.XX
  0b11111,  // XXXXX
  0b11011,  // XX.XX
  0b11111   // XXXXX
};

/**
 * -------------------------------------------------------------------------------------------------
 * Power / navigation
 * -------------------------------------------------------------------------------------------------
 */

// Power / standby
static const uint8_t PROGMEM power[] = {
  0b00100,  // ..X..
  0b10101,  // X.X.X
  0b10101,  // X.X.X
  0b10101,  // X.X.X
  0b10001,  // X...X
  0b10001,  // X...X
  0b10001,  // X...X
  0b01110   // .XXX.
};

// Sleep (crescent moon)
static const uint8_t PROGMEM sleep[] = {
  0b00110,  // ..XX.
  0b01100,  // .XX..
  0b11000,  // XX...
  0b11000,  // XX...
  0b11000,  // XX...
  0b11100,  // XXX..
  0b01111,  // .XXXX
  0b00110   // ..XX.
};

// Mains power / plugged in
static const uint8_t PROGMEM plug[] = {
  0b01010,  // .X.X.
  0b01010,  // .X.X.
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b01110,  // .XXX.
  0b00100,  // ..X..
  0b00100   // ..X..
};

static const uint8_t PROGMEM hourglass[] = {
  0b11111,  // XXXXX
  0b01110,  // .XXX.
  0b01110,  // .XXX.
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b01110,  // .XXX.
  0b01110,  // .XXX.
  0b11111   // XXXXX
};

static const uint8_t PROGMEM home[] = {
  0b00100,  // ..X..
  0b01110,  // .XXX.
  0b11111,  // XXXXX
  0b01110,  // .XXX.
  0b01110,  // .XXX.
  0b01110,  // .XXX.
  0b01010,  // .X.X.
  0b01010   // .X.X.
};

// Rotate left / anticlockwise
static const uint8_t PROGMEM rotateL[] = {
  0b00100,  // ..X..
  0b01000,  // .X...
  0b11110,  // XXXX.
  0b01001,  // .X..X
  0b00101,  // ..X.X
  0b00001,  // ....X
  0b10001,  // X...X
  0b01110   // .XXX.
};

// Rotate right / clockwise
static const uint8_t PROGMEM rotateR[] = {
  0b00100,  // ..X..
  0b00010,  // ...X.
  0b01111,  // .XXXX
  0b10010,  // X..X.
  0b10100,  // X.X..
  0b10000,  // X....
  0b10001,  // X...X
  0b01110   // .XXX.
};

static const uint8_t PROGMEM plus[] = {
  0b00000,  // .....
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b11111,  // XXXXX
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b00000,  // .....
  0b00000   // .....
};

static const uint8_t PROGMEM minus[] = {
  0b00000,  // .....
  0b00000,  // .....
  0b00000,  // .....
  0b11111,  // XXXXX
  0b00000,  // .....
  0b00000,  // .....
  0b00000,  // .....
  0b00000   // .....
};

static const uint8_t PROGMEM tick[] = {
  0b00000,  // .....
  0b00000,  // .....
  0b00001,  // ....X
  0b00010,  // ...X.
  0b10100,  // X.X..
  0b01000,  // .X...
  0b00000,  // .....
  0b00000   // .....
};

static const uint8_t PROGMEM cross[] = {
  0b00000,  // .....
  0b10001,  // X...X
  0b01010,  // .X.X.
  0b00100,  // ..X..
  0b01010,  // .X.X.
  0b10001,  // X...X
  0b00000,  // .....
  0b00000   // .....
};

// Tick cut out of a filled box: an outline leaves no room for one
static const uint8_t PROGMEM checkboxTicked[] = {
  0b00000,  // .....
  0b11111,  // XXXXX
  0b11101,  // XXX.X
  0b10101,  // X.X.X
  0b11011,  // XX.XX
  0b11111,  // XXXXX
  0b00000,  // .....
  0b00000   // .....
};

static const uint8_t PROGMEM checkboxEmpty[] = {
  0b00000,  // .....
  0b11111,  // XXXXX
  0b10001,  // X...X
  0b10001,  // X...X
  0b10001,  // X...X
  0b11111,  // XXXXX
  0b00000,  // .....
  0b00000   // .....
};

/**
 * -------------------------------------------------------------------------------------------------
 * Battery
 * battery0 (empty) ... battery5 (full)
 * -------------------------------------------------------------------------------------------------
 */

static const uint8_t PROGMEM battery0[] = {
  0b01110,  // .XXX.
  0b11111,  // XXXXX
  0b10001,  // X...X
  0b10001,  // X...X
  0b10001,  // X...X
  0b10001,  // X...X
  0b10001,  // X...X
  0b11111   // XXXXX
};

static const uint8_t PROGMEM battery1[] = {
  0b01110,  // .XXX.
  0b11111,  // XXXXX
  0b10001,  // X...X
  0b10001,  // X...X
  0b10001,  // X...X
  0b10001,  // X...X
  0b11111,  // XXXXX
  0b11111   // XXXXX
};

static const uint8_t PROGMEM battery2[] = {
  0b01110,  // .XXX.
  0b11111,  // XXXXX
  0b10001,  // X...X
  0b10001,  // X...X
  0b10001,  // X...X
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111   // XXXXX
};

static const uint8_t PROGMEM battery3[] = {
  0b01110,  // .XXX.
  0b11111,  // XXXXX
  0b10001,  // X...X
  0b10001,  // X...X
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111   // XXXXX
};

static const uint8_t PROGMEM battery4[] = {
  0b01110,  // .XXX.
  0b11111,  // XXXXX
  0b10001,  // X...X
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111   // XXXXX
};

static const uint8_t PROGMEM battery5[] = {
  0b01110,  // .XXX.
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111   // XXXXX
};

static const uint8_t PROGMEM batteryCharging[] = {
  0b01110,  // .XXX.
  0b11111,  // XXXXX
  0b10001,  // X...X
  0b10111,  // X.XXX
  0b10101,  // X.X.X
  0b11101,  // XXX.X
  0b10001,  // X...X
  0b11111   // XXXXX
};

static const uint8_t PROGMEM batteryError[] = {
  0b01110,  // .XXX.
  0b11111,  // XXXXX
  0b11011,  // XX.XX
  0b11011,  // XX.XX
  0b11011,  // XX.XX
  0b11111,  // XXXXX
  0b11011,  // XX.XX
  0b11111   // XXXXX
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
  0b00000,  // .....
  0b00000,  // .....
  0b00000,  // .....
  0b00000,  // .....
  0b00000,  // .....
  0b00000,  // .....
  0b10000,  // X....
  0b00000   // .....
};

static const uint8_t PROGMEM wifi1[] = {
  0b00000,  // .....
  0b00000,  // .....
  0b00000,  // .....
  0b00000,  // .....
  0b01000,  // .X...
  0b01000,  // .X...
  0b11000,  // XX...
  0b00000   // .....
};

static const uint8_t PROGMEM wifi2[] = {
  0b00000,  // .....
  0b00000,  // .....
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b01100,  // .XX..
  0b01100,  // .XX..
  0b11100,  // XXX..
  0b00000   // .....
};

static const uint8_t PROGMEM wifi3[] = {
  0b00010,  // ...X.
  0b00010,  // ...X.
  0b00110,  // ..XX.
  0b00110,  // ..XX.
  0b01110,  // .XXX.
  0b01110,  // .XXX.
  0b11110,  // XXXX.
  0b00000   // .....
};

static const uint8_t PROGMEM wifiDisconnected[] = {
  0b10001,  // X...X
  0b01010,  // .X.X.
  0b00100,  // ..X..
  0b01010,  // .X.X.
  0b10001,  // X...X
  0b00000,  // .....
  0b00100,  // ..X..
  0b00000   // .....
};

static const uint8_t PROGMEM wifiOff[] = {
  0b10000,  // X....
  0b01000,  // .X...
  0b00100,  // ..X..
  0b00010,  // ...X.
  0b00001,  // ....X
  0b00000,  // .....
  0b00100,  // ..X..
  0b00000   // .....
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
  0b10001,  // X...X
  0b10001,  // X...X
  0b10001,  // X...X
  0b10001,  // X...X
  0b10001,  // X...X
  0b10001,  // X...X
  0b10001,  // X...X
  0b11111   // XXXXX
};

static const uint8_t PROGMEM tank1[] = {
  0b10001,  // X...X
  0b10001,  // X...X
  0b10001,  // X...X
  0b10001,  // X...X
  0b10001,  // X...X
  0b10001,  // X...X
  0b11111,  // XXXXX
  0b11111   // XXXXX
};

static const uint8_t PROGMEM tank2[] = {
  0b10001,  // X...X
  0b10001,  // X...X
  0b10001,  // X...X
  0b10001,  // X...X
  0b10001,  // X...X
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111   // XXXXX
};

static const uint8_t PROGMEM tank3[] = {
  0b10001,  // X...X
  0b10001,  // X...X
  0b10001,  // X...X
  0b10001,  // X...X
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111   // XXXXX
};

static const uint8_t PROGMEM tank4[] = {
  0b10001,  // X...X
  0b10001,  // X...X
  0b10001,  // X...X
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111   // XXXXX
};

static const uint8_t PROGMEM tank5[] = {
  0b10001,  // X...X
  0b10001,  // X...X
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111   // XXXXX
};

static const uint8_t PROGMEM tank6[] = {
  0b10001,  // X...X
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111   // XXXXX
};

static const uint8_t PROGMEM tank7[] = {
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111   // XXXXX
};

static const uint8_t PROGMEM tankError[] = {
  0b10001,  // X...X
  0b10101,  // X.X.X
  0b10101,  // X.X.X
  0b10101,  // X.X.X
  0b10001,  // X...X
  0b10101,  // X.X.X
  0b10001,  // X...X
  0b11111   // XXXXX
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
  0b00000,  // .....
  0b01110,  // .XXX.
  0b01000,  // .X...
  0b01110,  // .XXX.
  0b00010,  // ...X.
  0b01110,  // .XXX.
  0b00000,  // .....
  0b00000   // .....
};

static const uint8_t PROGMEM badge4G[] = {
  0b00000,  // .....
  0b01010,  // .X.X.
  0b01010,  // .X.X.
  0b01110,  // .XXX.
  0b00010,  // ...X.
  0b00010,  // ...X.
  0b00000,  // .....
  0b00000   // .....
};

static const uint8_t PROGMEM badge3G[] = {
  0b00000,  // .....
  0b01110,  // .XXX.
  0b00010,  // ...X.
  0b01110,  // .XXX.
  0b00010,  // ...X.
  0b01110,  // .XXX.
  0b00000,  // .....
  0b00000   // .....
};

static const uint8_t PROGMEM badge2G[] = {
  0b00000,  // .....
  0b01110,  // .XXX.
  0b00010,  // ...X.
  0b01110,  // .XXX.
  0b01000,  // .X...
  0b01110,  // .XXX.
  0b00000,  // .....
  0b00000   // .....
};

static const uint8_t PROGMEM badgeLoRa[] = {
  0b10000,  // X....
  0b10000,  // X....
  0b10000,  // X....
  0b11110,  // XXXX.
  0b00000,  // .....
  0b11110,  // XXXX.
  0b10010,  // X..X.
  0b11110   // XXXX.
};

static const uint8_t PROGMEM badgeWifi[] = {
  0b10101,  // X.X.X
  0b10101,  // X.X.X
  0b11111,  // XXXXX
  0b00000,  // .....
  0b11101,  // XXX.X
  0b10001,  // X...X
  0b11101,  // XXX.X
  0b10001   // X...X
};

static const uint8_t PROGMEM bluetooth[] = {
  0b00100,  // ..X..
  0b00110,  // ..XX.
  0b10101,  // X.X.X
  0b01110,  // .XXX.
  0b01110,  // .XXX.
  0b10101,  // X.X.X
  0b00110,  // ..XX.
  0b00100   // ..X..
};

/**
 * -------------------------------------------------------------------------------------------------
 * Security / connection
 * -------------------------------------------------------------------------------------------------
 */

static const uint8_t PROGMEM lock[] = {
  0b01110,  // .XXX.
  0b10001,  // X...X
  0b10001,  // X...X
  0b11111,  // XXXXX
  0b11011,  // XX.XX
  0b11011,  // XX.XX
  0b11111,  // XXXXX
  0b00000   // .....
};

static const uint8_t PROGMEM unlock[] = {
  0b01110,  // .XXX.
  0b10001,  // X...X
  0b10000,  // X....
  0b11111,  // XXXXX
  0b11011,  // XX.XX
  0b11011,  // XX.XX
  0b11111,  // XXXXX
  0b00000   // .....
};

static const uint8_t PROGMEM key[] = {
  0b01110,  // .XXX.
  0b10001,  // X...X
  0b01110,  // .XXX.
  0b00100,  // ..X..
  0b00110,  // ..XX.
  0b00100,  // ..X..
  0b00110,  // ..XX.
  0b00000   // .....
};

static const uint8_t PROGMEM link[] = {
  0b11100,  // XXX..
  0b10100,  // X.X..
  0b10111,  // X.XXX
  0b10101,  // X.X.X
  0b11101,  // XXX.X
  0b00101,  // ..X.X
  0b00111,  // ..XXX
  0b00000   // .....
};

// Airplane mode
static const uint8_t PROGMEM airplane[] = {
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b01110,  // .XXX.
  0b11111,  // XXXXX
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b01110,  // .XXX.
  0b00000   // .....
};

/**
 * -------------------------------------------------------------------------------------------------
 * Other
 * -------------------------------------------------------------------------------------------------
 */

static const uint8_t PROGMEM plant[] = {
  0b00011,  // ...XX
  0b00111,  // ..XXX
  0b10110,  // X.XX.
  0b01100,  // .XX..
  0b00100,  // ..X..
  0b11111,  // XXXXX
  0b01110,  // .XXX.
  0b01110   // .XXX.
};

static const uint8_t PROGMEM waterDrop[] = {
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b01110,  // .XXX.
  0b01110,  // .XXX.
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b01110   // .XXX.
};

static const uint8_t PROGMEM clock[] = {
  0b01110,  // .XXX.
  0b10001,  // X...X
  0b10101,  // X.X.X
  0b10101,  // X.X.X
  0b10101,  // X.X.X
  0b11001,  // XX..X
  0b10001,  // X...X
  0b01110   // .XXX.
};

static const uint8_t PROGMEM faucet[] = {
  0b00100,  // ..X..
  0b01110,  // .XXX.
  0b00101,  // ..X.X
  0b01111,  // .XXXX
  0b11111,  // XXXXX
  0b11001,  // XX..X
  0b11000,  // XX...
  0b11000   // XX...
};

static const uint8_t PROGMEM cup[] = {
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b01110,  // .XXX.
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b01110   // .XXX.
};

static const uint8_t PROGMEM sound[] = {
  0b01001,  // .X..X
  0b11010,  // XX.X.
  0b11000,  // XX...
  0b11011,  // XX.XX
  0b11000,  // XX...
  0b11010,  // XX.X.
  0b01001,  // .X..X
  0b00000   // .....
};

static const uint8_t PROGMEM music[] = {
  0b01111,  // .XXXX
  0b01111,  // .XXXX
  0b01001,  // .X..X
  0b01001,  // .X..X
  0b01001,  // .X..X
  0b01001,  // .X..X
  0b11011,  // XX.XX
  0b11011   // XX.XX
};

static const uint8_t PROGMEM book[] = {
  0b10001,  // X...X
  0b11011,  // XX.XX
  0b10101,  // X.X.X
  0b10101,  // X.X.X
  0b10101,  // X.X.X
  0b10101,  // X.X.X
  0b10101,  // X.X.X
  0b01110   // .XXX.
};

static const uint8_t PROGMEM flag[] = {
  0b10000,  // X....
  0b11110,  // XXXX.
  0b10001,  // X...X
  0b11110,  // XXXX.
  0b10000,  // X....
  0b10000,  // X....
  0b10000,  // X....
  0b10000   // X....
};

static const uint8_t PROGMEM brightness[] = {
  0b00100,  // ..X..
  0b10101,  // X.X.X
  0b01110,  // .XXX.
  0b11111,  // XXXXX
  0b01110,  // .XXX.
  0b10101,  // X.X.X
  0b00100,  // ..X..
  0b00000   // .....
};

static const uint8_t PROGMEM contrast[] = {
  0b01110,  // .XXX.
  0b10111,  // X.XXX
  0b10111,  // X.XXX
  0b10111,  // X.XXX
  0b10111,  // X.XXX
  0b10111,  // X.XXX
  0b01110,  // .XXX.
  0b00000   // .....
};

// Material "grain"
static const uint8_t PROGMEM pattern[] = {
  0b00011,  // ...XX
  0b00011,  // ...XX
  0b11000,  // XX...
  0b11000,  // XX...
  0b00011,  // ...XX
  0b00011,  // ...XX
  0b11000,  // XX...
  0b11000   // XX...
};

static const uint8_t PROGMEM colour[] = {
  0b01110,  // .XXX.
  0b11101,  // XXX.X
  0b10111,  // X.XXX
  0b11111,  // XXXXX
  0b11100,  // XXX..
  0b11110,  // XXXX.
  0b01110,  // .XXX.
  0b00000   // .....
};

static const uint8_t PROGMEM bulbOn[] = {
  0b01110,  // .XXX.
  0b10001,  // X...X
  0b10001,  // X...X
  0b10001,  // X...X
  0b10001,  // X...X
  0b01010,  // .X.X.
  0b01110,  // .XXX.
  0b01110   // .XXX.
};

// Bulb with a line through it, like Home Assistant's lightbulb-off-outline
static const uint8_t PROGMEM bulbOff[] = {
  0b01110,  // .XXX.
  0b10001,  // X...X
  0b11001,  // XX..X
  0b10101,  // X.X.X
  0b10011,  // X..XX
  0b01010,  // .X.X.
  0b01110,  // .XXX.
  0b01110   // .XXX.
};

static const uint8_t PROGMEM cat[] = {
  0b10001,  // X...X
  0b11011,  // XX.XX
  0b11111,  // XXXXX
  0b10101,  // X.X.X
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b01110,  // .XXX.
  0b00000   // .....
};

// Blocked / not allowed
static const uint8_t PROGMEM blocked[] = {
  0b01110,  // .XXX.
  0b10001,  // X...X
  0b11001,  // XX..X
  0b10101,  // X.X.X
  0b10101,  // X.X.X
  0b10011,  // X..XX
  0b10001,  // X...X
  0b01110   // .XXX.
};

static const uint8_t PROGMEM doorOpen[] = {
  0b11111,  // XXXXX
  0b11001,  // XX..X
  0b11101,  // XXX.X
  0b11101,  // XXX.X
  0b11101,  // XXX.X
  0b11101,  // XXX.X
  0b11001,  // XX..X
  0b11111   // XXXXX
};

static const uint8_t PROGMEM doorClosed[] = {
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11101,  // XXX.X
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111,  // XXXXX
  0b11111   // XXXXX
};

// Walking person, like Home Assistant's motion-sensor
static const uint8_t PROGMEM motion[] = {
  0b00110,  // ..XX.
  0b00110,  // ..XX.
  0b01100,  // .XX..
  0b10110,  // X.XX.
  0b00101,  // ..X.X
  0b01010,  // .X.X.
  0b10010,  // X..X.
  0b10001   // X...X
};

/**
 * -------------------------------------------------------------------------------------------------
 * Scroll
 * -------------------------------------------------------------------------------------------------
 */

static const uint8_t PROGMEM triangleUp[] = {
  0b00000,  // .....
  0b00000,  // .....
  0b00100,  // ..X..
  0b01110,  // .XXX.
  0b11111,  // XXXXX
  0b00000,  // .....
  0b00000,  // .....
  0b00000   // .....
};

static const uint8_t PROGMEM triangleDown[] = {
  0b00000,  // .....
  0b00000,  // .....
  0b11111,  // XXXXX
  0b01110,  // .XXX.
  0b00100,  // ..X..
  0b00000,  // .....
  0b00000,  // .....
  0b00000   // .....
};

static const uint8_t PROGMEM triangleLeft[] = {
  0b00000,  // .....
  0b00100,  // ..X..
  0b01100,  // .XX..
  0b11100,  // XXX..
  0b01100,  // .XX..
  0b00100,  // ..X..
  0b00000,  // .....
  0b00000   // .....
};

static const uint8_t PROGMEM triangleRight[] = {
  0b00000,  // .....
  0b00100,  // ..X..
  0b00110,  // ..XX.
  0b00111,  // ..XXX
  0b00110,  // ..XX.
  0b00100,  // ..X..
  0b00000,  // .....
  0b00000   // .....
};

/**
 * -------------------------------------------------------------------------------------------------
 * Arrows (small)
 * -------------------------------------------------------------------------------------------------
 */

static const uint8_t PROGMEM arrowUpSmall[] = {
  0b00100,  // ..X..
  0b01110,  // .XXX.
  0b10101,  // X.X.X
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b00000,  // .....
  0b00000,  // .....
  0b00000   // .....
};

static const uint8_t PROGMEM arrowDownSmall[] = {
  0b00000,  // .....
  0b00000,  // .....
  0b00000,  // .....
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b10101,  // X.X.X
  0b01110,  // .XXX.
  0b00100   // ..X..
};

static const uint8_t PROGMEM arrowLeftSmall[] = {
  0b00000,  // .....
  0b00100,  // ..X..
  0b01000,  // .X...
  0b11111,  // XXXXX
  0b01000,  // .X...
  0b00100,  // ..X..
  0b00000,  // .....
  0b00000   // .....
};

static const uint8_t PROGMEM arrowRightSmall[] = {
  0b00000,  // .....
  0b00100,  // ..X..
  0b00010,  // ...X.
  0b11111,  // XXXXX
  0b00010,  // ...X.
  0b00100,  // ..X..
  0b00000,  // .....
  0b00000   // .....
};

static const uint8_t PROGMEM arrowReturnSmall[] = {
  0b00100,  // ..X..
  0b01000,  // .X...
  0b11111,  // XXXXX
  0b01001,  // .X..X
  0b00101,  // ..X.X
  0b00001,  // ....X
  0b00001,  // ....X
  0b00000   // .....
};

static const uint8_t PROGMEM arrowUpLongSmall[] = {
  0b00100,  // ..X..
  0b01110,  // .XXX.
  0b10101,  // X.X.X
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b00100   // ..X..
};

static const uint8_t PROGMEM arrowDownLongSmall[] = {
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b10101,  // X.X.X
  0b01110,  // .XXX.
  0b00100   // ..X..
};

/**
 * -------------------------------------------------------------------------------------------------
 * Arrows (small, solid)
 * -------------------------------------------------------------------------------------------------
 */

static const uint8_t PROGMEM arrowUpSmallSolid[] = {
  0b00100,  // ..X..
  0b01110,  // .XXX.
  0b11111,  // XXXXX
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b00000,  // .....
  0b00000,  // .....
  0b00000   // .....
};

static const uint8_t PROGMEM arrowDownSmallSolid[] = {
  0b00000,  // .....
  0b00000,  // .....
  0b00000,  // .....
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b11111,  // XXXXX
  0b01110,  // .XXX.
  0b00100   // ..X..
};

static const uint8_t PROGMEM arrowLeftSmallSolid[] = {
  0b00000,  // .....
  0b00100,  // ..X..
  0b01100,  // .XX..
  0b11111,  // XXXXX
  0b01100,  // .XX..
  0b00100,  // ..X..
  0b00000,  // .....
  0b00000   // .....
};

static const uint8_t PROGMEM arrowRightSmallSolid[] = {
  0b00000,  // .....
  0b00100,  // ..X..
  0b00110,  // ..XX.
  0b11111,  // XXXXX
  0b00110,  // ..XX.
  0b00100,  // ..X..
  0b00000,  // .....
  0b00000   // .....
};

static const uint8_t PROGMEM arrowReturnSmallSolid[] = {
  0b00100,  // ..X..
  0b01100,  // .XX..
  0b11111,  // XXXXX
  0b01101,  // .XX.X
  0b00101,  // ..X.X
  0b00001,  // ....X
  0b00001,  // ....X
  0b00000   // .....
};

static const uint8_t PROGMEM arrowUpLongSmallSolid[] = {
  0b00100,  // ..X..
  0b01110,  // .XXX.
  0b11111,  // XXXXX
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b00100   // ..X..
};

static const uint8_t PROGMEM arrowDownLongSmallSolid[] = {
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b00100,  // ..X..
  0b11111,  // XXXXX
  0b01110,  // .XXX.
  0b00100   // ..X..
};
}  // namespace icons_5x8
}  // namespace oli

#endif
