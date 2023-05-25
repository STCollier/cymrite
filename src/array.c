#include <cymrite/array.h>
#include <stdint.h>
#include <stdlib.h>

cymrite_Array cymrite_Array_create(const size_t size) {
	cymrite_Array array;
	array.data = malloc(sizeof(size_t) * size);
	array.size = size;
	return array;
}

void cymrite_Array_delete(cymrite_Array array) {
	free(array.data);
}

cymrite_Array cymrite_Array_insert(cymrite_Array array, const size_t index, const size_t value) {
	if (index <= array.size) {
		array.data = realloc(array.data, sizeof(size_t) * ++array.size);
		for (size_t i = array.size; i > index; --i) {
			array.data[i] = array.data[i - 1];
		}
		array.data[index] = value;
	}
	return array;
}

cymrite_Array cymrite_Array_erase(cymrite_Array array, const size_t index) {
	if (array.size && (index < array.size)) {
		for (size_t i = index; i < (array.size - 1); ++i) {
			array.data[i] = array.data[i + 1];
		}
		array.data = realloc(array.data, sizeof(size_t) * --array.size);
	}
	return array;
}

cymrite_Array cymrite_Array_push(cymrite_Array array, const size_t value) {
	return arrayInsert(array, array.size, value);
}

cymrite_Array cymrite_Array_pop(cymrite_Array array) {
	return arrayRemove(array, array.size - 1);
}

