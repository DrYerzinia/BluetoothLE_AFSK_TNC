// decimal_ring_buffer.c

#include "decimal_ring_buffer.h"

void decimal_ring_buffer_init(decimal_ring_buffer *self, unsigned short capacity) {

  self->size = capacity;
  self->data = (decimal*) malloc(sizeof(decimal) * capacity);

  self->read_position = 0;
  self->write_position = 0;

}

void decimal_ring_buffer_put(decimal_ring_buffer *self, decimal f) {

  self->data[self->write_position++] = f;

  if (self->write_position >= self->size)
    self->write_position = 0;

}

decimal decimal_ring_buffer_get(decimal_ring_buffer *self, unsigned short index) {

  unsigned short position = self->read_position + index;

  if (position >= self->size)
    position -= self->size;

  return self->data[position];

}

void decimal_ring_buffer_pop(decimal_ring_buffer *self) {

  self->read_position++;
  if (self->read_position >= self->size)
    self->read_position = 0;

}

void decimal_ring_buffer_remove(decimal_ring_buffer *self, unsigned short count) {

  self->read_position += count;

  if (self->read_position >= self->size)
    self->read_position -= self->size;

}

void decimal_ring_buffer_clear(decimal_ring_buffer *self) {

  self->read_position = 0;
  self->write_position = 0;

}

unsigned short decimal_ring_buffer_avail(decimal_ring_buffer *self) {

  if (self->read_position < self->write_position)
    return self->write_position - self->read_position;

  return self->write_position + self->size - self->read_position;

}

void decimal_ring_buffer_destory(decimal_ring_buffer *self) {

  free(self->data);

}
