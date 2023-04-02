#include <cymrite/array.h>
#include <stdio.h>

int main(void) {
	struct Array array = createArray();

	array = arrayAppend(array, (void*)'e');

	printf("%s\n", (char*)array.data);
}
