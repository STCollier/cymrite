#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "../include/cymrite/string.h"

int cymrite_countStringTokens(const char* string) {
	char* copy = malloc(strlen(string));
	strcpy(copy, string);

	int count = 0;
	char* token = strtok(copy, CYMRITE_WHITESPACE);

	while (token != NULL) {
		++count;
		token = strtok(NULL, CYMRITE_WHITESPACE);
	}

	return count;
}

int cymrite_countStringCharacter(const char* string, const char character) {
	int count = 0;

	for (size_t i = strlen(string); i--;) {
		count += (string[i] == character);
	}

	return count;
}

char* cymrite_uppercaseString(const char* string) {
	char* result = NULL;
	strcpy(result, string);
	for (size_t i = strlen(result); i--;) {
		result[i] = toupper(result[i]);
	}
	return result;
}

char* cymrite_lowercaseString(const char* string) {
	char* result = NULL;
	strcpy(result, string);
	for (size_t i = strlen(result); i--;) {
		result[i] = tolower(result[i]);
	}
	return result;
}

char* cymrite_repeatString(const char* string, size_t count) {
	char* result = NULL;
	while (count--) {
		strcat(result, string);
	}
	return result;
}

char* cymrite_trimStringFront(const char* string, const char* characters) {
	const size_t stringSize = strlen(string);
	size_t index = 0;

	while ((index < stringSize) && (strchr(characters, string[index]) != NULL)) {
		++index;
	}
	char* result = NULL;
	strcpy(result, string + index);
	return result;
}

char* cymrite_trimStringBack(const char* string, const char* characters) {
	char* result = NULL;
	strcpy(result, string);
	size_t index = strlen(string);

	while (index && (strchr(characters, string[index]) != NULL)) {
		--index;
	}

	result[index + 1] = 0;
	return result;
}

char* cymrite_truncateString(const char* string, const size_t length, const char* suffix) {
	const size_t stringSize = strlen(string);
	const size_t suffixSize = strlen(suffix);

	char* result = NULL;

	if (stringSize > length) {
		if (suffixSize > length) {
			strcpy(result, suffix);
			result[length + 1] = 0;
		} else {
			strcpy(result, string);
			result[length - suffixSize + 1] = 0;
			strcat(result, suffix);
		}
	}

	return result;
}
