#include <cymrite/gometry.h>
#include <cymrite/types.h>
#include <stdbool.h>

struct Rectangle createRectangle(const struct Vector2 pos, const double width, const double height) {
	struct Rectangle self;

	self.pos = pos;
	self.width = width;
	self.height = height;

	return self;
}

bool rectangleRectangleCollision(const struct Rectangle rect1, const struct Rectangle rect2) {
	return ((rect1.pos.x + rect1.width) >= rect2.pos.x)
		&& (rect1.pos.x <= (rect2.pos.x + rect2.width))
		&& ((rect1.pos.y + rect1.height) >= rect2.pos.y)
		&& (rect1.pos.y <= (rect2.pos.y + rect2.height));
}
