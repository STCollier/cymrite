#ifndef CYMRITE_STRING_H
#define CYMRITE_STRING_H

int numWords(char string[]);

int getNumChars(char string[], char c);

char* uppercase(char string[]);

char* lowercase(char string[]);

char* repeatStr(char string[], int iterations);

char* trimForwards(char string[], int num);

char* trimBackwards(char string[], int num);

char* truncateStr(char string[], int length, char* suffix);

#endif
