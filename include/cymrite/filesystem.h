#ifndef CYMRITE_HEADER_FILESYSTEM
#	define CYMRITE_HEADER_FILESYSTEM

#	include <stddef.h>

typedef struct {
	size_t size;
	char* data;
} cymrite_Buffer;

FILE* cymrite_openFile(const char* path, const char* mode);

void cymrite_closeFile(FILE* file);

cymrite_Buffer cymrite_readFile(const char* path);

void cymrite_writeFile(const char* path, const char* data);

void cymrite_copyFile(const char* sourcePath, const char* destinationPath);

cymrite_Buffer cymrite_getFileExtension(const char* path);

void cymrite_deleteFile(const char* path);

void cymrite_createDirectory(const char* path);

void cymrite_deleteDirectory(const char* path);

#endif
