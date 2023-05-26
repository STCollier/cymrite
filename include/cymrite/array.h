#ifndef CYMRITE_HEADER_ARRAY
#define CYMRITE_HEADER_ARRAY

#include <stddef.h>

typedef struct {
	size_t* data;
	size_t size;
} cymrite_Array;

cymrite_Array cymrite_createArray(size_t size);

void cymrite_arrayDelete(cymrite_Array* array);

void cymrite_arrayInsert(cymrite_Array* array, size_t index, size_t value);

int cymrite_arrayAt(cymrite_Array* array, size_t index);

int cymrite_arraySize(cymrite_Array* array);

void cymrite_arrayErase(cymrite_Array* array, size_t index);

void cymrite_arrayPush(cymrite_Array* array, size_t value);

void cymrite_arrayPop(cymrite_Array* array);

#endif // CYMRITE_HEADER_ARRAY
