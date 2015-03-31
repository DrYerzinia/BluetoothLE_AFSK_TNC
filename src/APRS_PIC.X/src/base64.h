#ifndef BASE64_H
#define	BASE64_H

#include <stdint.h>

uint16_t base64_encode(uint8_t *input, char *output, uint16_t len);
uint16_t base64_decode(char *s);

#endif

