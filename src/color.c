#include <stdint.h>
#include "../include/cymrite/color.h"

cymrite_Color cymrite_Color_create(const uint8_t red, const uint8_t green, const uint8_t blue) {
	cymrite_Color color;
	color.red = red;
	color.green = green;
	color.blue = blue;
	return color;
}

cymrite_Color cymrite_Color_fromValue(const uint32_t value) {
	return cymrite_Color_create(value >> 16, (value >> 8) & 255, value & 255);
}

uint32_t cymrite_Color_getValue(const cymrite_Color color) {
	return (color.red << 16) | (color.green << 8) | color.blue;
}
