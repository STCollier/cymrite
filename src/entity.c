#include <cymrite/entity.h>
#include <cymrite/types.h>

struct Entity createEntity(const double x, const double y) {
	static unsigned int nextID = 0;

	struct Entity self;

	self.ID = nextID++;
	self.pos.x = x;
	self.pos.y = y;

	return self;
}
