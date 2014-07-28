// char_array_expandable.h

#ifndef CHAR_ARRAY_EXPANDABLE_H
#define CHAR_ARRAY_EXPANDABLE_H

#include <stdlib.h>
#include <stdint.h>

typedef struct {

  uint16_t capacity;
  uint16_t length;

  int8_t *data;

} char_array_expandable;

#ifdef __cplusplus
extern "C" {
#endif

void char_array_expandable_init(char_array_expandable *self, uint16_t capacity);

void char_array_expandable_put(char_array_expandable *self, int8_t c);

uint16_t char_array_expandable_size(char_array_expandable *self);

void char_array_expandable_clear(char_array_expandable *self);

void char_array_expandable_destroy(char_array_expandable *self);

#ifdef __cplusplus
}
#endif

#endif
