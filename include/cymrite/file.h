#ifndef CYMRITE_HEADER_FILE
#define CYMRITE_HEADER_FILE

char* cymrite_getFileContent(const char* filename);

char* cymrite_getLineContent(const char* filename, int lineNumber);

void cymrite_writeToFile(const char* filename, char* data);

void cymrite_copyFile(const char* srcFilename, const char* destFilename);

#endif // CYMRITE_HEADER_FILE