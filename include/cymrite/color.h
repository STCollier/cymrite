#ifndef CYMRITE_HEADER_COLOR
	#define CYMRITE_HEADER_COLOR

	#include <stdint.h>

typedef struct {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
} cymrite_Color;

cymrite_Color cymrite_Color_create(uint8_t red, uint8_t green, uint8_t blue);

cymrite_Color cymrite_Color_fromValue(uint32_t value);

uint32_t cymrite_Color_getValue(cymrite_Color color);

#endif
