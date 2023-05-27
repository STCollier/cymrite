#include <cymrite/color.h>

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

cymrite_Color cymrite_createColor(const uint8_t red, const uint8_t green, const uint8_t blue) {
	cymrite_Color color;
	color.red = red;
	color.green = green;
	color.blue = blue;
	return color;
}

cymrite_Color cymrite_colorFromValue(const uint32_t value) {
	return cymrite_createColor(value >> 16, (value >> 8) & 255, value & 255);
}

uint32_t cymrite_getColorValue(const cymrite_Color color) {
	return (color.red << 16) | (color.green << 8) | color.blue;
}

bool cymrite_compareColor(const cymrite_Color color1, const cymrite_Color color2) {
	return (color1.red == color2.red)
		&& (color1.green == color2.green)
		&& (color1.blue == color2.blue);
}