#ifndef CYMRITE_GEOMETRY_H
#	define CYMRITE_GEOMETRY_H

#	include <cymrite/types.h>
#	include <stdbool.h>

struct Rectangle {
	struct Vector2 pos;
	double width;
	double height;
};

struct Rectangle createRectangle(struct Vector2 pos, double width, double height);

bool rectangleRectangleCollision(struct Rectangle rect1, struct Rectangle rect2);

#endif
