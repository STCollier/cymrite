#ifndef CYMRITE_COLOR_H
#	define CYMRITE_COLOR_H

#	include <stdbool.h>
#	include <stdint.h>

struct Color {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
};

struct Color createColor(uint8_t red, uint8_t green, uint8_t blue);

struct Color colorFromValue(uint32_t value);

uint32_t getColorValue(struct Color color);

bool compareColors(struct Color color1, struct Color color2);

#endif
