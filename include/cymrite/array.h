#ifndef CYMRITE_HEADER_ARRAY
#define CYMRITE_HEADER_ARRAY

#include <stddef.h>

typedef struct {
	size_t* data;
	size_t size;
} cymrite_Array;

cymrite_Array cymrite_Array_create(size_t size);

void cymrite_Array_delete(cymrite_Array* array);

void cymrite_Array_insert(cymrite_Array* array, size_t index, size_t value);

void cymrite_Array_erase(cymrite_Array* array, size_t index);

void cymrite_Array_push(cymrite_Array* array, size_t value);

void cymrite_Array_pop(cymrite_Array* array);

#endif // CYMRITE_HEADER_ARRAY
