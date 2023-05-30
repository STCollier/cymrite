#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <cymrite/file.h>

char* cymrite_getFileContent(const char* filename) {
  char* buffer = 0;
  long length;
  FILE* file = fopen(filename, strcmp(strrchr(filename, '.'), ".txt") == 0 ? "r" : "rb");

  if (file) {
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);
    buffer = malloc(length+1);

    if (buffer) {
     	fread(buffer, 1, length, file);
     	buffer[length] = '\0'; // Null terminate string
    }

    fclose(file);
    return buffer;

  } else {
   	fprintf(stderr, "Could not find file: %s\n", filename);
	exit(1);
  }

  free(buffer);

  return NULL;
}

char* cymrite_getLineContent(const char* filename, int lineNumber) {
    char* buffer = 0;
    int currentLine = 0;
    FILE* file = fopen(filename, strcmp(strrchr(filename, '.'), ".txt") == 0 ? "r" : "rb");

    if (file) {
        size_t buffer_size = 999;
        buffer = malloc(buffer_size);

        while (fgets(buffer, buffer_size, file) != NULL) {
            currentLine++;

            if (currentLine == lineNumber) {
                fclose(file);
                return buffer;
            }
        }

        fclose(file);
    } else {
        fprintf(stderr, "Could not find file: %s\n", filename);
        exit(1);
    }

    free(buffer);

    return NULL;
}

void cymrite_writeToFile(const char* filename, char* data) {
	FILE* file = fopen(filename, strcmp(strrchr(filename, '.'), ".txt") == 0 ? "w" : "wb");

	if (file) {
		if (strlen(data) > 0) {
			fputs(data, file);
		}

		fclose(file);
	} else {
		fprintf(stderr, "Could not find file: %s\n", filename);
        exit(1);
	}
}

void cymrite_copyFile(const char* srcFilename, const char* destFilename) {
	char* buffer = 0;
  	long length;

	FILE* file1 = fopen(srcFilename, strcmp(strrchr(srcFilename, '.'), ".txt") == 0 ? "r" : "rb");
	FILE* file2 = fopen(destFilename, strcmp(strrchr(destFilename, '.'), ".txt") == 0 ? "w" : "wb");

	if (file1) {
		fseek(file1, 0, SEEK_END);
	    length = ftell(file1);
	    fseek(file1, 0, SEEK_SET);
	    buffer = malloc(length+1);

	    if (buffer) {
	     	fread(buffer, 1, length, file1);
	     	buffer[length] = '\0'; // Null terminate string
	    }

	    fclose(file1);
	} else {
		fprintf(stderr, "Could not find source file: %s\n", srcFilename);
	}

	if (file2) {
		fputs(buffer, file2);
	} else {
		fprintf(stderr, "Could not find destination file: %s\n", destFilename);
	}
}