#include <ctype.h>
#include <cymrite/string.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

const char* cymrite_whitespace = "\x9\xa\xb\xc\xd\x20\x85\xa0\u1680\u2000\u2001\u2002\u2003\u2004\u2005\u2006\u2007\u2008\u2009\u200a\u2028\u2029\u202F\u205f\u3000";

size_t cymrite_countTokens(const char* string) {
	char* copy = malloc(strlen(string));
	strcpy(copy, string);

	size_t count = 0;
	char* token = strtok(copy, cymrite_whitespace);

	while (token != NULL) {
		++count;
		token = strtok(NULL, cymrite_whitespace);
	}

	return count;
}

size_t cymrite_countCharacter(const char* string, const char character) {
	size_t count = 0;

	for (size_t i = strlen(string); i--;) {
		count += (string[i] == character);
	}

	return count;
}

void cymrite_uppercase(const char* string, char* result) {
	strcpy(result, string);

	for (size_t i = strlen(result); i--;) {
		result[i] = toupper(result[i]);
	}
}

void cymrite_lowercase(const char* string, char* result) {
	strcpy(result, string);

	for (size_t i = strlen(result); i--;) {
		result[i] = tolower(result[i]);
	}
}

void cymrite_repeatString(const char* string, char* result, size_t count) {
	while (count--) {
		strcat(result, string);
	}
}

void cymrite_trimStringFront(const char* string, char* result, const char* characters) {
	const size_t stringSize = strlen(string);
	size_t index = 0;

	while ((index < stringSize) && (strchr(characters, string[index]) != NULL)) {
		++index;
	}

	strcpy(result, string + index);
}

void cymrite_trimStringBack(const char* string, char* result, const char* characters) {
	strcpy(result, string);
	size_t index = strlen(string);

	while (index && (strchr(characters, string[index]) != NULL)) {
		--index;
	}

	result[index + 1] = 0;
}

void cymrite_trimString(const char* string, char* result, const char* characters) {
	cymrite_trimStringFront(string, result, characters);
	cymrite_trimStringBack(string, result, characters);
}

void cymrite_truncateString(const char* string, char* result, const size_t length, const char* suffix) {
	const size_t stringSize = strlen(string);
	const size_t suffixSize = strlen(suffix);

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
}
