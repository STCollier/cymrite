#ifndef CYMRITE_HEADER_GEOMETRY
#define CYMRITE_HEADER_GEOMETRY

#include <stdbool.h>

typedef struct {
	float x;
	float y;
} cymrite_Vector2;

typedef struct {
	float x;
	float y;
	float z;
} cymrite_Vector3;

typedef struct {
	float x;
	float y;
} cymrite_Point;

typedef struct {
	float x1;
	float y1;
	float x2;
	float y2;
} cymrite_Line;

typedef struct {
	float x;
	float y;
	float radius;
} cymrite_Circle;

typedef struct {
	float x;
	float y;
	float width;
	float height;
} cymrite_Rectangle;

float cymrite_dist(cymrite_Line line);

bool cymrite_pointPoint(cymrite_Point point1, cymrite_Point point2);

bool cymrite_pointCircle(cymrite_Point point, cymrite_Circle circle);

bool cymrite_circleCircle(cymrite_Circle circle1, cymrite_Circle circle2);

bool cymrite_pointRectangle(cymrite_Point point, cymrite_Rectangle rectangle);

bool cymrite_rectangleRectangle(cymrite_Rectangle rectangle1, cymrite_Rectangle rectangle2);

bool cymrite_circleRectangle(cymrite_Circle circle, cymrite_Rectangle rectangle);

bool cymrite_lineLine(cymrite_Line line1, cymrite_Line line2);

bool cymrite_lineRectangle(cymrite_Line line, cymrite_Rectangle rectangle);

#endif // CYMRITE_HEADER_GEOMETRY
