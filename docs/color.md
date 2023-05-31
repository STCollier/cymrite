# Color

Defined in header [<cymrite/color.h>](../include/cymrite/color.h)

## `typedef struct cymrite_Color`

#### Description:
- A `typdef struct` that stores an RGB color value

### Synopsis
```c
typedef struct {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
} cymrite_Color;
```

<br/>


## `cymrite_Color cymrite_createColor(const uint8_t red, const uint8_t green, const uint8_t blue)`

#### Description:
- Function that creates a color using an red, green, and blue component (0-255). Note that an alternative approach to create a color is just using the `typdef struct cymrite_Color` explicitly, e.g. `cyrmiteColor red = {255, 0, 0};`

#### Parameters:
- `red`: an unsigned 8 bit integer, `const uint8_t red`, the red value of the created color
- `green`: an unsigned 8 bit integer, `const uint8_t green`, the green value of the created color
- `blue`: an unsigned 8 bit integer, `const uint8_t blue`, the blue value of the created color

#### Returns:
- `cymrite_Color`

### Example
```c
cymrite_Color myColor = cymrite_createColor(255, 0, 0);

printf("Red: (%d, %d, %d)", myColor.red, myColor.green, myColor.blue);
```
Output:
```
Red: (255, 0, 0)
```

<br/>


## `cymrite_Color cymrite_colorFromValue(uint32_t value)`

#### Description:
- Function that creates an RGB `cymrite_Color` color using an integer format

#### Parameters:
- `value`: an unsigned 32 bit integer, `uint32_t value` used to create the color

#### Returns:
- `cymriteColor`

### Example
```c
cymrite_Color color1 = cymrite_colorFromValue(0xFF0000); // Hex
cymrite_Color color2 = cymrite_colorFromValue(16744192); // Decimal

printf("Red: (%d, %d, %d)\n", color1.red, color1.green, color1.blue);
printf("Orange: (%d, %d, %d)\n", color2.red, color2.green, color2.blue);
```
Output:
```
Red: (255, 0, 0)
Orange: (255, 127, 0)
```

<br/>


## `uint32_t cymrite_getColorValue(const cymrite_Color color)`

#### Description:
- Function that returns the RGB color value of a `cymrite_Color` in integer format

#### Parameters:
- `color`: a `cymrite_Color`, used to convert to integer format

#### Returns:
- An unsigned 32 bit integer, `uint32_t`

### Example
```c
cymrite_Color orange = {255, 127, 0};

printf("Orange: %d\n", cymrite_getColorValue(orange));
```
Output:
```
Orange: 16744192
```

<br/>


## `bool cymrite_compareColor(const cymrite_Color color1, const cymrite_Color color2)`

#### Description:
- Function that checks if two `cymrite_Color`s are the same

#### Parameters:
- `color1`: a `cymrite_Color` to compare with `color2`
- `color2`: a `cymrite_Color` to compare with `color1`

#### Returns:
- A boolean, true (1) or false (0)

### Example
```c
cymrite_Color color1 = {255, 127, 0};
cymrite_Color color2 = {255, 0, 0};

printf("%s\n", cymrite_compareColor(color1, color2) ? "true" : "false");
```
Output:
```
false
```