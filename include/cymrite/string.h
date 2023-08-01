#ifndef CYMRITE_HEADER_STRING
#	define CYMRITE_HEADER_STRING

#	include <stddef.h>

#	define CYMRITE_WHITESPACE "\x9\xA\xB\xC\xD\x20\x85\xA0"

int cymrite_countStringTokens(const char* string);

int cymrite_countStringCharacter(const char* string, char character);

int cymrite_findStringLineIndex(const char* string, const char* line);

char* cymrite_uppercaseString(const char* string);

char* cymrite_lowercaseString(const char* string);

char* cymrite_repeatString(const char* string, size_t count);

char* cymrite_trimStringFront(const char* string, const char* characters);

char* cymrite_trimStringBack(const char* string, const char* characters);

char* cymrite_truncateString(const char* string, size_t length, const char* suffix);

#endif
