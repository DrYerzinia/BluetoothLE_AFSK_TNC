// crcccitt.c

#include "crcccitt.h"

uint16_t CRCCCITT(uint8_t *data, uint16_t len, uint16_t polynomial) {

  uint16_t crc = 0xFFFF;
  uint8_t i;

  while (len--) {

    crc ^= *data++;

    for (i = 0; i < 8; i++) {
      if (crc & 0x0001)
        crc = (crc >> 1) ^ polynomial;
      else
        crc >>= 1;
    }

  }

  crc ^= 0xFFFF;

  return crc;

}
