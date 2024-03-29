#include <stdint.h>
#include <stdlib.h>
#include "../include/cymrite/array.h"

cymrite_Array cymrite_Array_create(const size_t size) {
	cymrite_Array array;
	array.data = malloc(sizeof(size_t) * size);
	array.size = size;
	return array;
}

void cymrite_Array_destroy(cymrite_Array* array) {
	free(array->data);
	array->size = 0;
}

void cymrite_Array_insert(cymrite_Array* array, const size_t index, const size_t value) {
	if (index <= array->size) {
		array->data = realloc(array->data, sizeof(size_t) * ++array->size);
		for (size_t i = array->size; i > index; --i) {
			array->data[i] = array->data[i - 1];
		}
		array->data[index] = value;
	}
}

int cymrite_Array_at(cymrite_Array* array, size_t index) {
	return array->data[index];
}

int cymrite_Array_size(cymrite_Array* array) {
	return array->size;
}

void cymrite_Array_erase(cymrite_Array* array, const size_t index) {
	if (array->size && (index < array->size)) {
		for (size_t i = index; i < (array->size - 1); ++i) {
			array->data[i] = array->data[i + 1];
		}
		array->data = realloc(array->data, sizeof(size_t) * --array->size);
	}
}

void cymrite_Array_push(cymrite_Array* array, const size_t value) {
	return cymrite_Array_insert(array, array->size, value);
}

void cymrite_Array_pop(cymrite_Array* array) {
	return cymrite_Array_erase(array, array->size - 1);
}
