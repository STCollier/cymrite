#include "entity.h"
#include "types.h"

struct Entity init(double x, double y) {
    struct Entity self;

    self.ID = &self.ID;
    self.pos.x = x;
    self.pos.y = y;

    return self;
}

double entityGetX(struct Entity self) {
    return self.pos.x;
}

double entityGetY(struct Entity self) {
    return self.pos.y;
}

cym_vec2 entityGetPos(struct Entity self) {
    return self.pos;
}