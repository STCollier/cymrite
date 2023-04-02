#ifndef CYMRITE_ENTITY_H
#define CYMRITE_ENTITY_H

struct Entity {
    unsigned int ID;
    cym_vec2 pos;
};
struct Entity init(double x, double y);
double entityGetX(struct Entity self);
double entityGetY(struct Entity self);
cym_vec2 entityGetPos(struct Entity self);

#endif