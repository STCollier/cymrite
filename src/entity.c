#include <cymrite/entity.h>
#include <cymrite/types.h>

struct Entity createEntity(const double x, const double y) {
	static unsigned int nextID = 0;

	struct Entity entity;
	entity.ID = nextID++;
	entity.pos.x = x;
	entity.pos.y = y;
	return entity;
}
