#ifndef CYMRITE_HEADER_COLOR
#define CYMRITE_HEADER_COLOR

#include <stdbool.h>
#include <stdint.h>

typedef struct {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
} cymrite_Color;

cymrite_Color cymrite_createColor(uint8_t red, uint8_t green, uint8_t blue);

cymrite_Color cymrite_colorFromValue(uint32_t value);

uint32_t cymrite_getColorValue(cymrite_Color color);

bool cymrite_compareColor(cymrite_Color color1, cymrite_Color color2);

#endif // CYMRITE_HEADER_COLOR
