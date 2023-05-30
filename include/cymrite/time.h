#ifndef CYMRITE_HEADER_TIME
#define CYMRITE_HEADER_TIME

int cymrite_getYear();

int cymrite_getMonth();

int cymrite_getDay();

int cymrite_getHour(int format);

int cymrite_getMinute();

int cymrite_getSecond();

char* cymrite_getMeridiem();

char* cymrite_getWeekday();

char* cymrite_getMonthStr();

bool cymrite_isLeapYear();

#endif // CYMRITE_HEADER_TIME
