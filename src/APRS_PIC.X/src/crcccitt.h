// crcccitt.h

#ifndef CRCCCITT_H
#define CRCCCITT_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint16_t CRCCCITT(const uint8_t *data, uint16_t len, const uint16_t polynomial);

#ifdef __cplusplus
}
#endif

#endif
