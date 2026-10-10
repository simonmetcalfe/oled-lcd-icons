#ifndef OLI_ICONS_COMMON_H
#define OLI_ICONS_COMMON_H

/**
 * -------------------------------------------------------------------------------------------------
 * ICONS - COMMON
 *
 * Platform shims and small helpers shared by every size header.
 *
 * - Arduino (AVR, ESP32, ESP8266 ...): Arduino.h provides PROGMEM and pgm_read_*().
 * - AVR without Arduino: avr/pgmspace.h.
 * - Anything else (ESP-IDF, ESPHome with framework: esp-idf, host builds): PROGMEM is empty and
 *   reads are plain pointer dereferences.
 * -------------------------------------------------------------------------------------------------
 */

#include <stdint.h>

#if defined(ARDUINO)
#include <Arduino.h>
#elif defined(__AVR__)
#include <avr/pgmspace.h>
#endif

#ifndef PROGMEM
#define PROGMEM
#endif

#ifdef pgm_read_byte
#define OLI_READ_BYTE(addr) pgm_read_byte(addr)
#else
#define OLI_READ_BYTE(addr) (*(const uint8_t*)(addr))
#endif

#ifdef pgm_read_ptr
#define OLI_READ_PTR(addr) pgm_read_ptr(addr)
#else
#define OLI_READ_PTR(addr) (*(const void* const*)(addr))
#endif

namespace oli {

/**
 * Entry i of an icon set (a PROGMEM array of PROGMEM bitmaps), e.g. oli::frame(ic::batterySet, 3).
 */
inline const uint8_t* frame(const uint8_t* const* set, uint8_t i) {
  return (const uint8_t*)OLI_READ_PTR(&set[i]);
}

/**
 * Map 0-100 to a set index 0..levels-1 (levels > 0), e.g. oli::levelIndex(pct, ic::batteryLevels).
 */
inline uint8_t levelIndex(uint8_t percent, uint8_t levels) {
  uint16_t i = (uint16_t)percent * levels / 100;
  return i >= levels ? levels - 1 : (uint8_t)i;
}

}  // namespace oli

#endif
