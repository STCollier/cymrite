#include <cymrite/geometry.h>
#include <cymrite/types.h>
#include <stdbool.h>

struct Rectangle createRectangle(const struct Vector2 pos, const double width, const double height) {
	struct Rectangle rectangle;
	rectangle.pos = pos;
	rectangle.width = width;
	rectangle.height = height;
	return rectangle;
}

bool rectangleRectangleCollision(const struct Rectangle rectangle1, const struct Rectangle rectangle2) {
	return ((rectangle1.pos.x + rectangle1.width) >= rectangle2.pos.x)
		&& (rectangle1.pos.x <= (rectangle2.pos.x + rectangle2.width))
		&& ((rectangle1.pos.y + rectangle1.height) >= rectangle2.pos.y)
		&& (rectangle1.pos.y <= (rectangle2.pos.y + rectangle2.height));
}
