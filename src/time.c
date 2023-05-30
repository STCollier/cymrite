#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#include <cymrite/time.h>

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

int cymrite_getHour(int format) {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	if (format == 12) {
		if (tm.tm_hour > 12) {
			return tm.tm_hour - 12;
		}
	}

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
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	return tm.tm_hour > 12 ? "PM" : "AM";
}

char* cymrite_getWeekday() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	switch (tm.tm_wday) {
		case 0:
			return "Sunday";
			break;
		case 1:
			return "Monday";
			break;
		case 2:
			return "Tuesday";
			break;
		case 3:
			return "Wednesday";
			break;
		case 4:
			return "Thursday";
			break;
		case 5:
			return "Friday";
			break;
		case 6:
			return "Saturday";
			break;
	}

	return NULL; // Doomsday is nigh
}

char* cymrite_getMonthStr() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

 	switch (tm.tm_mon) {
 		case 0:
 			return "January";
 			break;
 		case 1:
 			return "February";
 			break;
 		case 2:
 			return "March";
 			break;
 		case 3:
 			return "April";
 			break;
 		case 4:
 			return "May";
 			break;
 		case 5:
 			return "June";
 			break;
 		case 6:
 			return "July";
 			break;
 		case 7:
 			return "August";
 			break;
 		case 8:
 			return "September";
 			break;
 		case 9:
 			return "October";
 			break;
 		case 10:
 			return "November";
 			break;
 		case 11:
 			return "December";
 			break;
 	}

 	return NULL;
}

bool cymrite_isLeapYear() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	return (tm.tm_year + 1900) % 4 == 0;
}