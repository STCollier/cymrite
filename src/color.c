#include <cymrite/color.h>
#include <stdbool.h>
#include <stdint.h>

struct Color createColor(const uint8_t red, const uint8_t green, const uint8_t blue, const uint8_t alpha) {
	struct Color result;
	result.red = red;
	result.green = green;
	result.blue = blue;
	result.alpha = alpha;
	return result;
}

struct Color createColor(const uint32_t value) {
	return createColor(value >> 24, value >> 16 & 255, value >> 8 & 255, value & 255);
}

uint32_t getColorValue(const struct Color color) {
	return (color.red << 24) + (color.green << 16) + (color.blue << 8) + color.alpha;
}

bool compareColors(const struct Color color1, const struct Color color2) {
	return (color1.red == color2.red)
		&& (color1.green == color2.green)
		&& (color1.blue == color2.blue)
		&& (color1.alpha == color2.alpha);
}
