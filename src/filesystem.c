#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../include/cymrite/filesystem.h"

FILE* cymrite_openFile(const char* const path, const char* const mode) {
	FILE* const file = fopen(path, mode);
	if (!file) {
		fprintf(stderr, "Failed to open file: %s\n", path);
		exit(EXIT_FAILURE);
	}
	return file;
}

void cymrite_closeFile(FILE* const file) {
	if (fclose(file)) {
		fprintf(stderr, "Failed to close file: %s\n", path);
		exit(EXIT_FAILURE);
	}
}

cymrite_Buffer cymrite_readFile(const char* const path) {
	FILE* const file = cymrite_openFile(path, "r");
	size_t chunkSize = 1024; // Arbitrary
	cymrite_Buffer result = {
		.size = 0,
		.data = malloc(chunkSize)
	};
	while (true) {
		if (!result.data) { // Catches both malloc() and realloc() failures
			fprintf(stderr, "Failed to allocate memory while reading file: %s\n", path);
			exit(EXIT_FAILURE);
		}
		const size_t bytesRead = fread(result.data + result.size, 1, chunkSize, file);
		if ((SIZE_MAX - result.size - 1) < bytesRead) { // Additional index for null-terminator
			fprintf(stderr, "Failed to read entire file: %s\n", path);
			exit(EXIT_FAILURE);
		}
		result.size += bytesRead;
		if (bytesRead == chunkSize) {
			chunkSize *= 2;
			result.data = realloc(result.data, result.size + chunkSize);
		} else {
			result.data[result.size++] = '\0';
			break;
		}
	}
	cymrite_closeFile(file);
	return result;
}

void cymrite_writeFile(const char* const path, const char* const data) {
	FILE* const file = cymrite_openFile(path, "w");
	if (strlen(data)) {
		fputs(data, file);
	}
	cymrite_closeFile(file);
}

void cymrite_copyFile(const char* const sourcePath, const char* const destinationPath) {
	char* data = cymrite_readFile(sourcePath);
	cymrite_writeFile(destinationPath, data);
	free(data);
}

cymrite_Buffer cymrite_getFileExtension(const char* const path) {
	char* data = strrchr(path, '.');
	return cymrite_Buffer {
		.size = strlen(path) - data + path, // Not sure if correct
		.data = data + 1
	};
}

void cymrite_deleteFile(const char* const path) {
	if (remove(path)) {
		fprintf(stderr, "Failed to delete file: %s\n", path);
		exit(EXIT_FAILURE);
	}
}

void cymrite_createDirectory(const char* const path) {
	struct stat st = { 0 };
	if (stat(path, &st) != -1) {
		fprintf(stderr, "Failed to create directory: %s\n", path);
		exit(EXIT_FAILURE);
	}
	mkdir(path, 0700);
}

void cymrite_removeDirectory(const char* const path) {
	struct stat st = { 0 };
	if (stat(path, &st) == -1) {
		fprintf(stderr, "Failed to delete directory: %s\n", path);
		exit(EXIT_FAILURE);
	}
	rmdir(path);
}
