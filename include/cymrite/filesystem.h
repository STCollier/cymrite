#ifndef CYMRITE_HEADER_FILE
#define CYMRITE_HEADER_FILE

char* cymrite_getFileContent(const char* filename);

char* cymrite_getLineContent(const char* filename, int lineNumber);

void cymrite_writeToFile(const char* filename, char* data);

void cymrite_copyFile(const char* srcFilename, const char* destFilename);

char* cymrite_getFileType(const char* filename);

int cymrite_getLineFromContent(const char* filename, char* data);

void cymrite_deleteFile(const char* filename);

void cymrite_createDirectory(const char* directoryName);

void cymrite_removeDirectory(const char* directoryName);

#endif // CYMRITE_HEADER_FILE