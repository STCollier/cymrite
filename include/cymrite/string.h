#ifndef CYMRITE_HEADER_STRING
#	define CYMRITE_HEADER_STRING 

#	include <stddef.h>

#	define CYMRITE_WHITESPACE "\x9\xA\xB\xC\xD\x20\x85\xA0"

int cymrite_countStringTokens(const char* string);

int cymrite_countStringCharacters(const char* string, char character);

int cymrite_findStringLineIndex(const char* string, const char* line);

void cymrite_uppercase(const char* string, char* result);

void cymrite_lowercase(const char* string, char* result);

void cymrite_repeatString(const char* string, char* result, size_t count);

void cymrite_trimStringFront(const char* string, char* result, const char* characters);

void cymrite_trimStringBack(const char* string, char* result, const char* characters);

void cymrite_truncateString(const char* string, char* result, size_t length, const char* suffix);

#endif
