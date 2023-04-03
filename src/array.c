#include <cymrite/array.h>
#include <stdint.h>
#include <stdlib.h>

struct Array createArray() {
	struct Array array;
	array.data = malloc(0);
	array.size = 0;
	return array;
}

void deleteArray(struct Array array) {
	free(array.data);
}

struct Array arrayInsert(struct Array array, const size_t index, const size_t value) {
	if (index <= array.size) {
		array.data = realloc(array.data, ++array.size);
		for (size_t i = array.size; i > index; --i)
			array.data[i] = array.data[i - 1];
		array.data[index] = value;
	}
	return array;
}

struct Array arrayRemove(struct Array array, const size_t index) {
	if (array.size && (index < array.size)) {
		for (size_t i = index; i < array.size - 1; ++i)
			array.data[i] = array.data[i + 1];
		array.data = realloc(array.data, --array.size);
	}
	return array;
}

struct Array arrayAppend(struct Array array, const size_t value) {
	return arrayInsert(array, array.size, value);
}

struct Array arrayPop(struct Array array) {
	return arrayRemove(array, array.size - 1);
}

