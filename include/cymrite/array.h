#ifndef CYMRITE_ARRAY_H
#	define CYMRITE_ARRAY_H

#	include <stddef.h>

struct Array {
	size_t* data;
	size_t size;
};

struct Array createArray();

void deleteArray(struct Array array);

struct Array arrayInsert(struct Array array, size_t index, size_t value);

struct Array arrayRemove(struct Array array, size_t index);

struct Array arrayAppend(struct Array array, size_t value);

struct Array arrayPop(struct Array array);

#endif
