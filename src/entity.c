#include <cymrite/entity.h>
#include <stddef.h>

cymrite_Entity cymrite_Entity_create(const double x, const double y) {
	static size_t nextID = 0;

	cymrite_Entity entity;
	entity.ID = nextID++;
	entity.position.x = x;
	entity.position.y = y;
	return entity;
}
