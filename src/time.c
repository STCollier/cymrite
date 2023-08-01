#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "../include/cymrite/time.h"

int cymrite_getYear() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	return tm.tm_year + 1900;
}

int cymrite_getMonth() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	return tm.tm_mon + 1;
}

int cymrite_getDay() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	return tm.tm_mday;
}

int cymrite_getHour() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	return tm.tm_hour;
}

int cymrite_getMinute() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	return tm.tm_min;
}

int cymrite_getSecond() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	return tm.tm_sec;
}

char* cymrite_getMeridiem() {
	return (cymrite_getHour() > 12) ? "PM" : "AM";
}

char* cymrite_getWeekday() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	switch (tm.tm_wday) {
	case 0:
		return "Sunday";
	case 1:
		return "Monday";
	case 2:
		return "Tuesday";
	case 3:
		return "Wednesday";
	case 4:
		return "Thursday";
	case 5:
		return "Friday";
	case 6:
		return "Saturday";
	default:
		// Doomsday is nigh
		return NULL;
	}
}

char* cymrite_getMonthStr() {
	switch (cymrite_getMonth()) {
	case 1:
		return "January";
	case 2:
		return "February";
	case 3:
		return "March";
	case 4:
		return "April";
	case 5:
		return "May";
	case 6:
		return "June";
	case 7:
		return "July";
	case 8:
		return "August";
	case 9:
		return "September";
	case 10:
		return "October";
	case 11:
		return "November";
	case 12:
		return "December";
	default:
		return NULL;
	}
}

bool cymrite_isLeapYear() {
	const int year = cymrite_getYear();
	return !(year % 4) && (year % 100) || !(year % 400);
}
