#ifndef CYMRITE_HEADER_FILESYSTEM
#	define CYMRITE_HEADER_FILESYSTEM

#	include <stddef.h>

char* cymrite_readFile(const char* filePath);

void cymrite_writeFile(const char* filePath, const char* data);

void cymrite_copyFile(const char* sourceFilePath, const char* destinationFilePath);

char* cymrite_getFileExtension(const char* filePath);

void cymrite_deleteFile(const char* filePath);

void cymrite_createDirectory(const char* directoryPath);

void cymrite_deleteDirectory(const char* directoryPath);

#endif
