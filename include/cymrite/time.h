#ifndef CYMRITE_HEADER_TIME
	#define CYMRITE_HEADER_TIME

	#include <stdbool.h>

int cymrite_getYear();

int cymrite_getMonth();

int cymrite_getDay();

int cymrite_getHour();

int cymrite_getMinute();

int cymrite_getSecond();

char* cymrite_getMeridiem();

char* cymrite_getWeekDay();

char* cymrite_getMonthName();

bool cymrite_isLeapYear();

#endif
