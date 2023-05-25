#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include <cymrite/string.h>


int numWords(char string[]) {
	char unmodified[strlen(string) + 1];
    strcpy(unmodified, string);

	int words = 0;
	char* token = strtok(string, " ");

	while(token != NULL) {
		words++;

		token = strtok(NULL, " ");
	}

	strcpy(string, unmodified);
	return words;
}

int getNumChars(char string[], char c) {
	int chars = 0;

	for (size_t i = 0; i < strlen(string); i++) {
		if (string[i] == c) chars++;
	}

	return chars;
}

char* uppercase(char string[]) {
	char* upper = malloc(strlen(string) + 1);
    strcpy(upper, string);

	for (size_t i = 0; i < strlen(upper); i++) {
		upper[i] = toupper(upper[i]);
	}

	return upper;
}

char* lowercase(char string[]) {
	char* lower = malloc(strlen(string) + 1);
    strcpy(lower, string);

	for (size_t i = 0; i < strlen(lower); i++) {
		lower[i] = tolower(lower[i]);
	}

	return lower;
}

char* repeatStr(char string[], int iterations) {
	char* str = malloc((strlen(string) * iterations) + 1);

	for (int i = 0; i < iterations; i++) {
		strcat(str, string);
	}

	//Trim trailing whitespace
	if (str[strlen(str)-1] == ' ') {
		str[strlen(str)-1] = '\0';
	}

	return str;
}

char* trimForwards(char string[], int num) {
	char* str = malloc(num + 1);

	if ((size_t) num <= strlen(string) && num > 0) {
		strncpy(str, string, num);

		return str;
	}

	return NULL;
}

char* trimBackwards(char string[], int num) {
	char* str = malloc(num + 1);

	if ((size_t) num <= strlen(string) && num > 0) {
		strncpy(str, string + strlen(string) - num, num);

		return str;
	}

	return NULL;
}

char* truncateStr(char string[], int length, char* suffix) {
	char* str = malloc(length + 1);

	if (length > 0) {
		strncpy(str, string, length - strlen(suffix));
		strcat(str, suffix);

		return str;
	}

	return NULL;
}