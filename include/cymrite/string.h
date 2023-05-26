#ifndef CYMRITE_HEADER_STRING
#define CYMRITE_HEADER_STRING

#include <stddef.h>

int cymrite_countTokens(const char* string);

int cymrite_countChar(const char* string, char character);

void cymrite_upper(const char* string, char* result);

void cymrite_lower(const char* string, char* result);

void cymrite_repeatStr(const char* string, char* result, size_t count);

void cymrite_trimFront(const char* string, char* result, const char* characters);

void cymrite_trimBack(const char* string, char* result, const char* characters);

void cymrite_truncateStr(const char* string, char* result, size_t length, const char* suffix);

extern char* cymrite_whitespace;

#endif // CYMRITE_HEADER_STRING
