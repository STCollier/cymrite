# Strings

Defined in header [<cymrite/string.h>](https://github.com/STCollier/cymrite/blob/main/include/cymrite/string.h)

## `int numWords(char string[])`
**Description:**
- Returns the number of words from a given string. To qualify as a word, a sequence of letters must be separated by a single space.

**Parameters:**
- `string`: a char array, `char string[]`, the value to get the number of words from, separated by single spaces

**Returns:**
- An integer

### Example
```c
char str[] = "Hello, this is a test string!";

printf("%d\n", numWords(str));
```
Output:
```
6
```

## `int getNumChars(char string[], char c)`
**Description:**
- Returns the number of a given character from a given string, case sensitive.

**Parameters:**
- `string`: a char array, `char string[]`, the string value to get the number of chars from
- `c`: a single char, `char c`, the selected character value to use

**Returns:**
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

## `char* uppercase(char string[])`
**Description:**
- Converts all the letters of a string to uppercase

**Parameters:**
- `string`: a char array, `char string[]`, the string value to convert to uppercase

**Returns:**
- A `char*` pointer

### Example
```c
printf("%s\n", uppercase("hello world!"));
```
Output:
```
HELLO WORLD!
```

## `char* lowercase(char string[])`
**Description:**
- Converts all the letters of a string to lowercase

**Parameters:**
- `string`: a char array, `char string[]`, the string value to convert to lowercase

**Returns:**
- A `char*` pointer

### Example
```c
printf("%s\n", lowercase("HELLO WORLD!"));
```
Output:
```
hello world!
```

## `char* repeatStr(char string[], int iterations)`
**Description:**
- Repeats a given string a set amount of times

**Parameters:**
- `string`: a char array, `char string[]`, the string value to convert to lowercase
- `iterations`: an integer, `int iterations`, the value determinting the amount of times to repeat the string

**Returns:**
- A `char*` pointer

### Example
```c
printf("%s", repeatStr("Hello!\n", 3));
```
Output:
```
Hello!
Hello!
Hello!
```

## `char* trimFront(char string[], int num)`
**Description:**
- Trims a string from the front with a given character length

**Parameters:**
- `string`: a char array, `char string[]`, the string value to trim
- `num`: an integer, `int num`, the value determining the length to trim

**Returns:**
- A `char*` pointer

### Example
```c
char str[] = "Hello World";

printf("%s\n", trimFront(str, 5));
```
Output:
```
Hello
```

## `char* trimBack(char string[], int num)`
**Description:**
- Trims a string from the back with a given character length

**Parameters:**
- `string`: a char array, `char string[]`, the string value to trim
- `num`: an integer, `int num`, the value determining the length to trim

**Returns:**
- A `char*` pointer

### Example
```c
char str[] = "Hello World";

printf("%s\n", trimBack(str, 5));
```
Output:
```
World
```

## `char* truncateStr(char string[], int length, char* suffix)`
**Description:**
- Truncates a string to a given length and appends a suffix to the end

**Parameters:**
- `string`: a char array, `char string[]`, the string value to truncate
- `length`: an integer, `int length`, value determining the length of the string to truncate. Keep in mind that the `length` applies to the string _plus_ the length of the suffix.
- `suffix`: a char pointer, `char* suffix`, the string value to append at the end of the truncated string. 

**Returns:**
- A `char*` pointer

### Example
```c
printf("%s\n", truncateStr("Hello World", 8, "..."));
```
Output:
```
Hello...
```

