#ifndef CYMRITE_ENTITY_H
#	define CYMRITE_ENTITY_H

#include <cymrite/types.h>

struct Entity {
	unsigned int ID;
	struct Vector2 pos;
};

struct Entity createEntity(double x, double y);

#endif
