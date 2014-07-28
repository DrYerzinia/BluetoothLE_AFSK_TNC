// char_ring_buffer.c

#include "char_ring_buffer.h"

void char_ring_buffer_init(char_ring_buffer *self, unsigned short capacity) {

  self->size = capacity;
  self->data = (signed char*) malloc(sizeof(char) * capacity);

  self->read_position = 0;
  self->write_position = 0;

}

void char_ring_buffer_put(char_ring_buffer *self, signed char c) {

  self->data[self->write_position++] = c;

  if (self->write_position >= self->size)
    self->write_position = 0;

}

signed char char_ring_buffer_get(char_ring_buffer *self, unsigned short index) {

  unsigned short position = self->read_position + index;

  if (position >= self->size)
    position -= self->size;

  return self->data[position];

}

void char_ring_buffer_pop(char_ring_buffer *self) {

  self->read_position++;
  if (self->read_position >= self->size)
    self->read_position = 0;

}

void char_ring_buffer_remove(char_ring_buffer *self, unsigned short count) {

  self->read_position += count;

  if (self->read_position >= self->size)
    self->read_position -= self->size;

}

void char_ring_buffer_clear(char_ring_buffer *self) {

  self->read_position = 0;
  self->write_position = 0;

}

unsigned short char_ring_buffer_avail(char_ring_buffer *self) {

  if (self->read_position <= self->write_position)
    return self->write_position - self->read_position;

  return self->write_position + self->size - self->read_position;

}

void char_ring_buffer_destory(char_ring_buffer *self) {

  free(self->data);

}
