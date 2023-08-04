# Math

Defined in header [<cymrite/math.h>](../include/cymrite/math.h)


## `typedef struct cymrite_Vector2`

#### Description:
- A `typedef struct` for creating a 2 dimensional vector, storing a `x` and `y` component

### Synopsis
```c
typedef struct {
	float x;
	float y;
} cymrite_Vector2;
```

<br/>


## `typedef struct cymrite_Vector2`

#### Description:
- A `typedef struct` for creating a 3 dimensional vector, storing a `x`, `y` and `z` component

### Synopsis
```c
typedef struct {
	float x;
	float y;
	float z;
} cymrite_Vector3;
```

<br/>

## `double cymrite_clamp(const double value, const double limit1, const double limit2)`

#### Description:
- Clamps a number within a certain range

#### Parameters:
- `value`: a number value, `const double value`, the value clamp
- `limit1`: a number value, `const double limit1`, the first limit to clamp
- `limit2`: a number value, `const double limit2`, the second limit to clamp

#### Returns:
- A double

### Example
```c
double foo = 12;

printf("%lf", cymrite_clamp(foo, 0, 10));
```
Output:
```
10.000000
```

<br/>


## `bool cymrite_almostEqual(const double value1, const double value2)`

#### Description:
- Determines if two doubles are almost equal (disregarding certain floating point impricision)

#### Parameters:
- `value1`: a number value, `const double value1`, the first value to check
- `value2`: a number value, `const double value2`, the second value to check

#### Returns:
- A boolean

### Example
```c
printf("%s", 0.1 + 0.2 == 0.3 ? "true\n" : "false\n");
printf("%s", cymrite_almostEqual(0.1 + 0.2, 0.3) ? "true\n" : "false\n");
```
Output:
```
false
true
```

<br/>

## `CYMRITE_PI`

#### Description:
- A macro storing the value of pi

### Example
```c
printf("%f", CYMRITE_PI);
```
Output:
```
3.141593
```

<br/>


## `CYMRITE_TAU`

#### Description:
- A macro storing the value of tau (2pi)

### Example
```c
printf("%f", CYMRITE_TAU);
```
Output:
```
6.283185
```

<br/>


## `CYMRITE_MIN(a, b)`

#### Description:
- A macro that determines the minimum value of two numbers

### Example
```c
printf("%d", CYMRITE_MIN(5, 10));
```
Output:
```
5
```

<br/>


## `CYMRITE_MAX(a, b)`

#### Description:
- A macro that determines the maximum value of two numbers

### Example
```c
printf("%d", CYMRITE_MIN(5, 10));
```
Output:
```
10
```