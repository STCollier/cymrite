#ifndef CYMRITE_ARRAY_H
#	define CYMRITE_ARRAY_H

#	include <stddef.h>

struct Array {
	void** data;
	size_t size;
};

struct Array createArray();

void deleteArray(struct Array array);

struct Array arrayInsert(struct Array array, size_t index, void* value);

struct Array arrayRemove(struct Array array, size_t index);

struct Array arrayAppend(struct Array array, void* value);

struct Array arrayPop(struct Array array);

#endif
