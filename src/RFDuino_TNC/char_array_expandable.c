// char_array_expandable.c

#include "char_array_expandable.h"

void char_array_expandable_init(char_array_expandable *self, uint16_t capacity) {

  self->length = 0;
  self->capacity = capacity;

  self->data = (int8_t*) malloc(sizeof(int8_t) * capacity);

}

void char_array_expandable_put(char_array_expandable *self, int8_t c) {

  if (self->length == self->capacity) {

    uint16_t old_capacity = self->capacity;

    self->capacity += self->capacity / 5;

    int8_t *new_data = (int8_t*) malloc(sizeof(int8_t) * self->capacity);
    int8_t *old_data = self->data;

    uint16_t i;
    for (i = 0; i < old_capacity; i++)
      new_data[i] = old_data[i];

    free(old_data);

    self->data = new_data;

  }

  self->data[self->length] =  c;

  self->length++;

}

uint16_t char_array_expandable_size(char_array_expandable *self) {

  return self->length;

}

void char_array_expandable_clear(char_array_expandable *self) {

  self->length = 0;

}

void char_array_expandable_destroy(char_array_expandable *self) {

  free(self->data);

}
