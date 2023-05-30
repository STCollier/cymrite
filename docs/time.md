# Time

Defined in header [<cymrite/time.h>](../include/cymrite/time.h)


## `int cymrite_getYear()`

#### Description:
- Returns the current year

#### Parameters:
- None

#### Returns:
- An integer

### Example
```c
printf("Current year is %d\n", cymrite_getYear());
```
Output:
```
Current year is 2023
```

<br/>


## `int cymrite_getMonth()`

#### Description:
- Returns the current month in the form of an integer from 1-12 (e.g. 1 = January, 2 = February, etc.)

#### Parameters:
- None

#### Returns:
- An integer

### Example
```c
printf("The current month is %d\n", cymrite_getMonth());
```
Output:
```
The current month is 5
```

<br/>


## `int cymrite_getHour(int format)`

#### Description:
- Returns the current hour in either 12 or 24 hour format

#### Parameters:
- `format`: an integer `int format` to specify 12 or 24 hour time. If the integer `12` is specified, time will default to 12 hours and any other integer will default to 24 hour time. 

#### Returns:
- An integer

### Example
```c
printf("It is %d o'clock\n", cymrite_getHour(12)); // 12 hour format
```
Output:
```
It is 6 o'clock
```

<br/>


## `int cymrite_getMinute()`

#### Description:
- Returns the current minute of an hour (0-59). It is recommended to use the `%02d` integer specifier when printing to correctly format minutes less than 10.

#### Parameters:
- None

#### Returns:
- An integer

### Example
```c
printf("The time is %d:%02d %s\n", cymrite_getHour(12), cymrite_getMinute());
```
Output:
```
The time is 6:07
```

<br/>

## `int cymrite_getSecond()`

#### Description:
- Returns the current second of an minute (0-59). It is recommended to use the `%02d` integer specifier when printing to correctly format seconds less than 10.

#### Parameters:
- None

#### Returns:
- An integer

### Example
```c
printf("The current second is %02d\n", cymrite_getSecond());
```
Output:
```
The current second is 55
```

<br/>


## `char* cymrite_getMeridiem()`

#### Description:
- Returns whether the time is ante meridiem (AM) or post meridiem (PM)

#### Parameters:
- None

#### Returns:
- A string (char pointer)

### Example
```c
printf("It is %d:%02d %s\n", cymrite_getHour(12), cymrite_getMinute(), cymrite_getMeridiem());
```
Output:
```
It is 4:30 PM
```

<br/>


## `char* cymrite_getWeekday()`

#### Description:
- Returns the current weekday as a string (e.g. Sunday, Monday, etc.)

#### Parameters:
- None

#### Returns:
- A string (char pointer)

### Example
```c
printf("Today is a %s\n", cymrite_getWeekday());
```
Output:
```
Today is a Friday
```

<br/>


## `char* cymrite_getMonthStr()`

#### Description:
- Returns the current month as a string (e.g. January, February, etc.)

#### Parameters:
- None

#### Returns:
- A string (char pointer)

### Example
```c
printf("The current month is %s\n", cymrite_getMonthStr());
```
Output:
```
The current month is May 
```

<br/>


## `bool cymrite_isLeapYear()`

#### Description:
- Returns whether the current year is a leap year or not

#### Parameters:
- None

#### Returns:
- A boolean true (1) or false (0)

### Example
```c
printf("%d %s a leap year\n", cymrite_getYear(), cymrite_isLeapYear(cymrite_getYear()) ? "is" : "is not");
```
Output:
```
2023 is not a leap year
```