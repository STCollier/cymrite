#ifndef CYMRITE_HEADER_STRING
#define CYMRITE_HEADER_STRING

#include <stddef.h>

const char* cymrite_whitespace = "\u0009\u000A\u000B\u000C\u000D\u0020\u0085\u00A0\u1680\u2000\u2001\u2002\u2003\u2004\u2005\u2006\u2007\u2008\u2009\u200A\u2028\u2029\u202F\u205F\u3000";

size_t cymrite_countTokens(const char* string);

size_t cymrite_countCharacter(const char* string, char character);

void cymrite_uppercase(const char* string, char* result);

void cymrite_lowercase(const char* string, char* result);

void cymrite_repeatString(const char* string, char* result, size_t count);

void cymrite_trimStringFront(const char* string, char* result, const char* characters);

void cymrite_trimStringBack(const char* string, char* result, const char* characters);

void cymrite_trimString(const char* string, char* result, const char* characters);

void truncate(const char* string, char* result, size_t length, const char* suffix);

#endif // CYMRITE_HEADER_STRING
