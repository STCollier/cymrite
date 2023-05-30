# Files

Defined in header [<cymrite/file.h>](../include/cymrite/file.h)


## `char* cymrite_getFileContent(const char* filename)`

#### Description:
- Returns the complete file contents of a given file

#### Parameters:
- `filename`: a char array, `const char* filename`, the filename to get the content from

#### Returns:
- A string (char pointer)

### Example
```c
printf("%s", cymrite_getFileContent("foo.txt"));
```
Output:
```
Hello World!

Testing 123
```

<br/>

## `char* cymrite_getLineContent(const char* filename, int lineNumber)`

#### Description:
- Returns the contents of a file from a given line. Returns `NULL` if the selected line is out of range of the file

#### Parameters:
- `filename`: a char pointer, `const char* filename`, the filename to get the content from
- `lineNumber`: an integer, `int lineNumber`, the selected line number to get the content from

#### Returns:
- A string (char pointer)

### Example
```c
printf("%s", cymrite_getLineContent("foo.txt", 3));
```
Output:
```
Testing 123
```

<br/>


## `void cymrite_writeToFile(const char* filename, char* data)`

#### Description:
- Writes given data to selected file. All previous file contents will be overwritten

#### Parameters:
- `filename`: a char pointer, `const char* filename`, the filename to write the data to
- `data`: a char pointer, `char* data`, the data to write to the file

#### Returns:
- Void

### Example
```c
cymrite_writeToFile("foo.txt", "Hello\nWorld");

printf("%s", cymrite_getFileContent("foo.txt"));
```
Output:
```
Hello
World
```

<br/>


## `void cymrite_copyFile(const char* srcFilename, const char* destFilename)`

#### Description:
- Copies the contents of one file over to another

#### Parameters:
- `srcFilename`: a char pointer, `const char* srcFilename`, the source filename to copy the contents from
- `destFilename`: a char pointer, `const char* destFilename`, the destination filename to write the contents to

#### Returns:
- Void

### Example
```c
cymrite_copyFile("foo.txt", "bar.txt");

printf("%s\n", cymrite_getFileContent("foo.txt"));
printf("%s\n", cymrite_getFileContent("bar.txt"));
```
Output:
```
Hello World!
Hello World!
```