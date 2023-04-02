#include <cymrite/color.h>
#include <stdbool.h>
#include <stdint.h>

struct Color createColor(const uint8_t red, const uint8_t green, const uint8_t blue) {
	struct Color color;
	color.red = red;
	color.green = green;
	color.blue = blue;
	return color;
}

struct Color colorFromValue(const uint32_t value) {
	return createColor(value >> 16, value >> 8 & 255, value & 255);
}

uint32_t getColorValue(const struct Color color) {
	return (color.red << 16) + (color.green << 8) + color.blue;
}

bool compareColors(const struct Color color1, const struct Color color2) {
	return (color1.red == color2.red)
		&& (color1.green == color2.green)
		&& (color1.blue == color2.blue);
}
