#ifndef CYMRITE_GEOMETRY_H
#define CYMRITE_GEOMETRY_H

struct Rectangle {
    cym_vec2 pos;
    double width;
    double height;
};

struct Rectangle init(cym_vec2 pos, double width, double height);
int rectangleRectangleCollide(struct Rectangle rect1, struct Rectangle rect2);

#endif