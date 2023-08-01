#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../include/cymrite/filesystem.h"

char* cymrite_readFile(const char* const filePath) {
	FILE* const file = fopen(filePath, strcmp(strrchr(filePath, '.'), ".txt") ? "rb" : "r");
	if (!file) {
		fprintf(stderr, "Could not open file: %s\n", filePath);
		return NULL;
	}
	fseek(file, 0, SEEK_END);
	const size_t length = ftell(file);
	fseek(file, 0, SEEK_SET);
	char* buffer = malloc(length + 1);
	if (buffer) {
		fread(buffer, sizeof(char), length, file);
		buffer[length] = '\0';
	}
	fclose(file);
	return buffer;
}

void cymrite_writeFile(const char* const filePath, const char* const data) {
	FILE* const file = fopen(filePath, strcmp(strrchr(filePath, '.'), ".txt") ? "wb" : "w");
	if (!file) {
		fprintf(stderr, "Could not open file: %s\n", filePath);
		return;
	}
	if (strlen(data)) {
		fputs(data, file);
	}
	fclose(file);
}

void cymrite_copyFile(const char* const sourceFilePath, const char* const destinationFilePath) {
	FILE* const file1 = fopen(sourceFilePath, strcmp(strrchr(sourceFilePath, '.'), ".txt") ? "rb" : "r");
	if (!file1) {
		fprintf(stderr, "Could not open file: %s\n", sourceFilePath);
		return;
	}
	FILE* const file2 = fopen(destinationFilePath, strcmp(strrchr(destinationFilePath, '.'), ".txt") ? "wb" : "w");
	if (!file2) {
		fprintf(stderr, "Could not open file: %s\n", destinationFilePath);
		return;
	}
	fseek(file1, 0, SEEK_END);
	const size_t length = ftell(file1);
	fseek(file1, 0, SEEK_SET);
	char* const buffer = malloc(length + 1);
	if (buffer) {
		fread(buffer, 1, length, file1);
		buffer[length] = '\0';
	}
	fclose(file1);
	fputs(buffer, file2);
	fclose(file2);
}

char* cymrite_getFileExtension(const char* const filePath) {
	return strrchr(filePath, '.') + 1;
}

void cymrite_deleteFile(const char* const filePath) {
	if (remove(filePath)) {
		fprintf(stderr, "Could not delete file: %s\n", filePath);
	}
}

void cymrite_createDirectory(const char* const directoryPath) {
	struct stat st = { 0 }; // ???
	if (stat(directoryPath, &st) != -1) {
		fprintf(stderr, "Creating directory with this name will result in an overwrite\n");
	}
	mkdir(directoryPath, 0700); // ???
}

void cymrite_removeDirectory(const char* const directoryPath) {
	struct stat st = { 0 }; // ???
	if (stat(directoryPath, &st) == -1) {
		fprintf(stderr, "Could not delete directory: %s\n", directoryPath);
		return;
	}
	rmdir(directoryPath);
}
