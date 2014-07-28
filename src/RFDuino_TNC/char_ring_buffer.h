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

#ifdef __cplusplus
extern "C" {
#endif

void char_ring_buffer_init(char_ring_buffer *self, unsigned short capacity);

void char_ring_buffer_put(char_ring_buffer *self, signed char c);
signed char char_ring_buffer_get(char_ring_buffer *self, unsigned short index);
void char_ring_buffer_pop(char_ring_buffer *self);
void char_ring_buffer_remove(char_ring_buffer *self, unsigned short count);

void char_ring_buffer_clear(char_ring_buffer *self);

unsigned short char_ring_buffer_avail(char_ring_buffer *self);

void char_ring_buffer_destory(char_ring_buffer *self);

#ifdef __cplusplus
}
#endif

#endif
