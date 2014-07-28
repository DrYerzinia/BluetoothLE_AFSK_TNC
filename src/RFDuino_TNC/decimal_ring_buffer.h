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

#ifdef __cplusplus
extern "C" {
#endif

void decimal_ring_buffer_init(decimal_ring_buffer *self, unsigned short capacity);

void decimal_ring_buffer_put(decimal_ring_buffer *self, decimal f);
decimal decimal_ring_buffer_get(decimal_ring_buffer *self, unsigned short index);
void decimal_ring_buffer_pop(decimal_ring_buffer *self);
void decimal_ring_buffer_remove(decimal_ring_buffer *self, unsigned short count);

void decimal_ring_buffer_clear(decimal_ring_buffer *self);

unsigned short decimal_ring_buffer_avail(decimal_ring_buffer *self);

void decimal_ring_buffer_destory(decimal_ring_buffer *self);

#ifdef __cplusplus
}
#endif

#endif
