#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <cymrite/filesystem.h>

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

char* cymrite_getFileType(const char* filename) {
	return strrchr(filename, '.') + 1;
}

int cymrite_getLineFromContent(const char* filename, char* data) {
	char* buffer = 0;
    int currentLine = 0;
    FILE* file = fopen(filename, strcmp(strrchr(filename, '.'), ".txt") == 0 ? "r" : "rb");

    if (file) {
        size_t buffer_size = 999;
        buffer = malloc(buffer_size);

        while (fgets(buffer, buffer_size, file) != NULL) {
            currentLine++;

            if (strstr(buffer, data) != NULL) {
            	fclose(file);

            	return currentLine;
            }
        }

        fclose(file);
    } else {
        fprintf(stderr, "Could not find file: %s\n", filename);
        exit(1);
    }

    free(buffer);

    return -1;
}

void cymrite_deleteFile(const char* filename) {
    if (remove(filename) != 0) {
        fprintf(stderr, "Unable to delete file: %s\n", filename);
    }
}

void cymrite_createDirectory(const char* directoryName) {
    struct stat st = {0};

    if (stat(directoryName, &st) == -1) {
        mkdir(directoryName, 0700);
    } else {
        fprintf(stderr, "Creating directory with this name will result in an overwrite\n");
    }
}

void cymrite_removeDirectory(const char* directoryName) {
    struct stat st = {0};

    if (stat(directoryName, &st) != -1) {
        rmdir(directoryName);
    } else {
        fprintf(stderr, "Unable to delete directory\n");
    }
}