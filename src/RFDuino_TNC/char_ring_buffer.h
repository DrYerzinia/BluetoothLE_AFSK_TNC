// char_ring_buffer.h

#ifndef CHAR_RING_BUFFER_H
#define CHAR_RING_BUFFER_H

#include <stdlib.h>

typedef struct {

  signed char *data;

  unsigned short read_position;
  unsigned short write_position;

  unsigned short size;

} char_ring_buffer;

static inline void char_ring_buffer_init(char_ring_buffer *self, unsigned short capacity) {

  self->size = capacity;
  self->data = (signed char*) malloc(sizeof(char) * capacity);

  self->read_position = 0;
  self->write_position = 0;

}

static inline void char_ring_buffer_put(char_ring_buffer *self, signed char c) {

  self->data[self->write_position++] = c;

  if (self->write_position >= self->size)
    self->write_position = 0;

}

static inline signed char char_ring_buffer_get(char_ring_buffer *self, unsigned short index) {

  unsigned short position = self->read_position + index;

  if (position >= self->size)
    position -= self->size;

  return self->data[position];

}

static inline void char_ring_buffer_pop(char_ring_buffer *self) {

  self->read_position++;
  if (self->read_position >= self->size)
    self->read_position = 0;

}

static inline void char_ring_buffer_remove(char_ring_buffer *self, unsigned short count) {

  self->read_position += count;

  if (self->read_position >= self->size)
    self->read_position -= self->size;

}

static inline void char_ring_buffer_clear(char_ring_buffer *self) {

  self->read_position = 0;
  self->write_position = 0;

}

static inline unsigned short char_ring_buffer_avail(char_ring_buffer *self) {

  if (self->read_position <= self->write_position)
    return self->write_position - self->read_position;

  return self->write_position + self->size - self->read_position;

}

static inline void char_ring_buffer_destory(char_ring_buffer *self) {

  free(self->data);

}

#endif
