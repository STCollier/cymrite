#ifndef CYMRITE_HEADER_GEOMETRY
#define CYMRITE_HEADER_GEOMETRY

#include <cymrite/types.h>
#include <stdbool.h>

typedef struct {
	cymrite_Vector2 position;
	cymrite_Vector2 size;
} cymrite_Rectangle;

cymrite_Rectangle cymrite_Rectangle_create(cymrite_Vector2 position, cymrite_Vector2 size);

bool cymrite_Rectangle_hasCollision(cymrite_Rectangle rectangle1, cymrite_Rectangle rectangle2);

#endif // CYMRITE_HEADER_GEOMETRY
