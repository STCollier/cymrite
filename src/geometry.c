#include "types.h"
#include "geometry.h"

struct Rectangle init(cym_vec2 pos, double width, double height) {
    struct Rectangle self;

    self.pos = pos;
    self.width = width;
    self.height = height;

    return self;
}

int rectangleRectangleCollide(struct Rectangle rect1, struct Rectangle rect2) {
    if (rect1.pos.x + rect1.width >= rect2.pos.x &&
        rect1.pos.x <= rect2.pos.x + rect2.width &&
        rect1.pos.y + rect1.height >= rect2.pos.y &&
        rect1.pos.y <= rect2.pos.y + rect2.height) {
        return 1;
    }
    return 0;
}
