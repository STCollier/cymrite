# Strings

Defined in header [<cymrite/string.h>](../include/cymrite/string.h)


## `int cymrite_countTokens(const char* string)`

#### Description:
- Returns the number of words from a given string.

#### Parameters:
- `string`: a char array, `const char* string`, the value to get the number of words from

#### Returns:
- An integer

### Example
```c
char str[] = "Hello, this is a test string!";

printf("%d\n", cymrite_countTokens(str));
```
Output:
```
6
```

<br/>

## `int cymrite_countChar(const char* string, const char character)`

#### Description:
- Returns the number of a given character from a given string, case sensitive.

#### Parameters:
- `string`: a char pointer, `const char* string`, the string value to get the number of chars from
- `character`: a single char, `const char character`, the selected character value to use

#### Returns:
- An integer


### Example
```c
char str[] = "Hello World!";

printf("%d\n", getNumChars(str, 'l'));
```
Output:
```
3
```

<br/>


## `void cymrite_upper(const char* string, char* result)`

#### Description:
- Converts all the letters of a string to uppercase

#### Parameters:
- `string`: a char pointer, `const char* string`, the string value to convert to uppercase
- `result`: a char pointer, `char* result`, which stores the new capitilized value of the string

#### Returns:
- Void

### Example
```c
char str[] = "Hello World!";
char* newStr = malloc(strlen(str)); //Using a dynamically allocated pointer

cymrite_upper(str, newStr);

printf("%s\n", newStr);

free(newStr);
```
Output:
```
HELLO WORLD!
```

<br/>


## `void cymrite_lower(const char* string, char* result)`

#### Description:
- Converts all the letters of a string to lowercase

#### Parameters:
- `string`: a char pointer, `const char* string`, the string value to convert to lowercase
- `result`: a char pointer, `char* result`, which stores the new uncapitilized value of the string

#### Returns:
- Void

### Example
```c
char str[] = "HELLO WORLD!";
char* newStr = malloc(strlen(str)); //Using a dynamically allocated pointer

cymrite_lower(str, newStr);

printf("%s\n", newStr);

free(newStr);
```
Output:
```
hello world!
```

<br/>


## `void cymrite_repeatStr(const char* string, char* result, size_t count)`

#### Description:
- Repeats a given string a set amount of times

#### Parameters:
- `string`: a char pointer, `const char* string`, the string value to repeat
- `result`: a char pointer, `char* result`, which stores the result of the repeated string
- `count`: a size_t unsigned value, `size_t count`, which determines the amount of times to repeat the string

#### Returns:
- Void

### Example
```c
char str[] = "Hello World!\n";
char result[128];

cymrite_repeatStr(str, result, 3);

printf("%s", result);
```
Output:
```
Hello World!
Hello World!
Hello World!
```

<br/>


## `void cymrite_trimFront(const char* string, char* result, const char* characters)`

#### Description:
- Trims given characters from a string from the front

#### Parameters:
- `string`: a char pointer, `const char* string`, the string value to trim
- `result`: a char pointer, `char* result`, which stores the result of the trimmed string
- `characters`: a char pointer, `const char* characters`, determining the section of the string to trim (starting from the front)

#### Returns:
- Void

### Example
```c
char str[] = "Hello World!";
char result[64];

cymrite_trimFront(str, result, "Hello ");

printf("%s\n", result);
```
Output:
```
World!
```

<br/>


## `cymrite_trimBack(const char* string, char* result, const char* characters)`

#### Description:
- Trims given characters from a string from the back

#### Parameters:
- `string`: a char pointer, `const char* string`, the string value to trim
- `result`: a char pointer, `char* result`, which stores the result of the trimmed string
- `characters`: a char pointer, `const char* characters`, determining the section of the string to trim (starting from the back)

#### Returns:
- Void

### Example
```c
char str[] = "Hello World!";
char result[64];

cymrite_trimBack(str, result, " World!");

printf("%s\n", result);
```
Output:
```
Hello
```

<br/>


## `void cymrite_truncateStr(const char* string, char* result, size_t length, const char* suffix)`

#### Description:
- Truncates a string to a given length and appends a suffix to the end

#### Parameters:
- `string`: a char pointer, `const char* string`, the string value to truncate
- `result`: a char pointer, `const char* result`, which stores the result of the truncated string
- `length`: a size_t unsigned value, `size_t length`, which determines the length of the string to be truncated (starting from 0). Keep in mind that this total length applies to the length of the suffix as well (see example below).
- `suffix`: a char pointer, `const char* suffix`, the suffix to append at the end of the string

#### Returns:
- Void

### Example
```c
char str[] = "Hello World!";
char result[64];

cymrite_truncateStr(str, result, 7, "...");

printf("%s\n", result);
```
Output:
```
Hello...
```

<br/>


## `char* cymrite_whitespace`

#### Description:
- A string containing whitespace characters

### Synopsis
```c
char* cymrite_whitespace = "\x9\xa\xb\xc\xd\x20\x85\xa0\u1680\u2000\u2001\u2002\u2003\u2004\u2005\u2006\u2007\u2008\u2009\u200a\u2028\u2029\u202F\u205f\u3000";
```

<br/>
