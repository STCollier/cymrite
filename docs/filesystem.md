# File System

Defined in header [<cymrite/filesystem.h>](../include/cymrite/filesystem.h)


## `char* cymrite_getFileContent(const char* filePath)`

#### Description:
- Returns the complete file contents of a given file
	
#### Parameters:
- `filePath`: a char array, `const char* filePath`, the filePath to get the content from

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


## `void cymrite_writeToFile(const char* filePath, const char* data)`

#### Description:
- Writes given data to selected file. All previous file contents will be overwritten

#### Parameters:
- `filePath`: a char pointer, `const char* filePath`, the filePath to write the data to
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
- `srcFilename`: a char pointer, `const char* srcFilename`, the source filePath to copy the contents from
- `destFilename`: a char pointer, `const char* destFilename`, the destination filePath to write the contents to

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

<br/>


## `char* cymrite_getFileType(const char* filePath)`

#### Description:
- Returns the file type of a given file

#### Parameters:
- `filePath`: a char pointer, `const char* filePath`, the filePath to return the file type of

#### Returns:
- A string (char pointer)

### Example
```c
const char* files[3] = {
	"foo.zip",
	"document.pdf",
	"bar.txt"
};

for (int i = 0; i < 3; i++) {
	printf("%s\n", cymrite_getFileType(files[i]));
}
```
Output:
```
zip
pdf
txt
```

<br/>


## `int cymrite_getLineFromContent(const char* filePath, char* data)`

#### Description:
- Returns the first found line number of a file based on a string. Returns `-1` if the string does not exist within the file 

#### Parameters:
- `filePath`: a char pointer, `const char* filePath`, the filePath to search with the given data
- `data`: a char pointer, `char* data`, the data to search the given file with

#### Returns:
- An integer

### Example
```c
// (foo.txt)
/*
Hello World!

Testing 123
*/

printf("Line: %d\n", cymrite_getLineFromContent("foo.txt", "Testing"));
```
Output:
```
Line: 3
```

<br/>


## `void cymrite_deleteFile(const char* filePath)`

#### Description:
- Deletes a given file if it exists

#### Parameters:
- `filePath`: a char pointer, `const char* filePath`, the filePath to delete

#### Returns:
- Void

### Example
```c
cymrite_deleteFile("foo.txt");
```

<br/>


## `void cymrite_createDirectory(const char* directoryName)`

#### Description:
- Creates a directory with a given name. The directory will not be created if it will result in an overwrite

#### Parameters:
- `directoryName`: a char pointer, `const char* directoryName`, the name of the directory to create

#### Returns:
- Void

### Example
```c
cymrite_createDirectory("files");
```

<br/>


## `void cymrite_removeDirectory(const char* directoryName)`

#### Description:
- Deletes a directory with a given name if it exists

#### Parameters:
- `directoryName`: a char pointer, `const char* directoryName`, the name of the directory to delete

#### Returns:
- Void

### Example
```c
cymrite_deleteDirectory("files");
```