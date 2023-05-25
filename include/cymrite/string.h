#ifndef CYMRITE_HEADER_STRING
#define CYMRITE_HEADER_STRING

#include <stddef.h>

extern const char* cymrite_whitespace;

size_t cymrite_countTokens(const char* string);

size_t cymrite_countCharacter(const char* string, char character);

void cymrite_uppercase(const char* string, char* result);

void cymrite_lowercase(const char* string, char* result);

void cymrite_repeatString(const char* string, char* result, size_t count);

void cymrite_trimStringFront(const char* string, char* result, const char* characters);

void cymrite_trimStringBack(const char* string, char* result, const char* characters);

void cymrite_trimString(const char* string, char* result, const char* characters);

void cymrite_truncateString(const char* string, char* result, size_t length, const char* suffix);

#endif // CYMRITE_HEADER_STRING
