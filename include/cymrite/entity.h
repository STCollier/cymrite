#ifndef CYMRITE_HEADER_ENTITY
#define CYMRITE_HEADER_ENTITY

#include <cymrite/types.h>
#include <stddef.h>

typedef struct {
	size_t id;
	cymrite_Vector2 position;
} cymrite_Entity;

cymrite_Entity cymrite_Entity_create(double x, double y);

#endif // CYMRITE_HEADER_ENTITY
