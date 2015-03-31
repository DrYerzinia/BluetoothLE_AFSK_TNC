// decimal_ring_buffer.h

#ifndef DECIMAL_RING_BUFFER_H
#define DECIMAL_RING_BUFFER_H

#include <stdlib.h>

#include "decimal.h"

typedef struct {

  decimal *data;

  unsigned short read_position;
  unsigned short write_position;

  unsigned short size;

} decimal_ring_buffer;

static inline void decimal_ring_buffer_init(decimal_ring_buffer *self, unsigned short capacity) {

  self->size = capacity;
  self->data = (decimal*) malloc(sizeof(decimal) * capacity);

  self->read_position = 0;
  self->write_position = 0;

}

static inline void decimal_ring_buffer_put(decimal_ring_buffer *self, decimal f) {

  self->data[self->write_position++] = f;

  if (self->write_position >= self->size)
    self->write_position = 0;

}

static inline decimal decimal_ring_buffer_get(decimal_ring_buffer *self, unsigned short index) {

  unsigned short position = self->read_position + index;

  if (position >= self->size)
    position -= self->size;

  return self->data[position];

}

static inline void decimal_ring_buffer_pop(decimal_ring_buffer *self) {

  self->read_position++;
  if (self->read_position >= self->size)
    self->read_position = 0;

}

static inline void decimal_ring_buffer_remove(decimal_ring_buffer *self, unsigned short count) {

  self->read_position += count;

  if (self->read_position >= self->size)
    self->read_position -= self->size;

}

static inline void decimal_ring_buffer_clear(decimal_ring_buffer *self) {

  self->read_position = 0;
  self->write_position = 0;

}

static inline unsigned short decimal_ring_buffer_avail(decimal_ring_buffer *self) {

  if (self->read_position < self->write_position)
    return self->write_position - self->read_position;

  return self->write_position + self->size - self->read_position;

}

static inline void decimal_ring_buffer_destory(decimal_ring_buffer *self) {

  free(self->data);

}

#endif
