#include <cymrite/geometry.h>
#include <cymrite/types.h>
#include <stdbool.h>

cymrite_Rectangle cymrite_Rectangle_create(const cymrite_Vector2 position, const cymrite_Vector2 size) {
	cymrite_Rectangle rectangle;
	rectangle.position = position;
	rectangle.size = size;
	return rectangle;
}

bool cymrite_Rectangle_hasCollision(const cymrite_Rectangle rectangle1, const cymrite_Rectangle rectangle2) {
	return ((rectangle1.position.x >= rectangle2.position.x) && (rectangle1.position.x <= (rectangle2.position.x + rectangle2.size.x)) || (rectangle2.position.x >= rectangle1.position.x) && (rectangle2.position.x <= (rectangle1.position.x + rectangle1.size.x))) && ((rectangle1.position.y >= rectangle2.position.y) && (rectangle1.position.y <= (rectangle2.position.y + rectangle2.size.y)) || (rectangle2.position.y >= rectangle1.position.y) && (rectangle2.position.y <= (rectangle1.position.y + rectangle1.size.y)));
}
