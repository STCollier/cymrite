#include <cymrite/array.h>
#include <cymrite/color.h>
#include <stddef.h>
#include <stdio.h>

int main(void) {
	struct Array array = createArray();

	array = arrayAppend(array, getColorValue(createColor(255, 0, 0)));

	for (size_t i = 0; i < array.size; ++i)
		printf("#%zx\n", array.data[i]);
}
