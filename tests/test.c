#include <cymrite/array.h>
#include <cymrite/color.h>
#include <cymrite/string.h>

#include <stddef.h>
#include <stdio.h>

int main(void) {
	/*struct Array array = createArray();

	array = arrayAppend(array, getColorValue(createColor(255, 0, 0)));

	for (size_t i = 0; i < array.size; ++i)
		printf("#%zx\n", array.data[i]);*/


	char str[] = "Hello, this is a test string!";
	char str2[] = "HELLO WORLD";

	printf("Words: %d\n", numWords(str));
	printf("Num of char 'e': %d\n", getNumChars(str, 'e'));
	printf("Uppercase string: %s\n", uppercase(str));
	printf("Lowercase string: %s\n", lowercase(str2));
	printf("Repeated: %s\n", repeatStr("hello ", 3));
	printf("Trimmed forward: %s\n", trimForwards(str2, 5));
	printf("Trimmed backwards: %s\n", trimBackwards(str2, 5));
	printf("Truncated: %s\n", truncateStr(str2, 8, "..."));
}
