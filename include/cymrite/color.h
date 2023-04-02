#ifndef CYMRITE_COLOR_H
#	define CYMRITE_COLOR_H

#	include <stdbool.h>
#	include <stdint.h>

struct Color {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	uint8_t alpha;
};

struct Color createColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255);

struct Color createColor(uint32_t value);

uint32_t getColorValue(struct Color color);

bool compareColors(struct Color color1, struct Color color2);

#endif
