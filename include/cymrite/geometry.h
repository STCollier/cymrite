#ifndef CYMRITE_HEADER_GEOMETRY
	#define CYMRITE_HEADER_GEOMETRY

	#include <stdbool.h>
	#include "./math.h"

typedef cymrite_Vector2 cymrite_Point;

typedef struct {
	double x1;
	double y1;
	double x2;
	double y2;
} cymrite_Line;

typedef struct {
	double x;
	double y;
	double radius;
} cymrite_Circle;

typedef struct {
	double x;
	double y;
	double width;
	double height;
} cymrite_Rectangle;

double cymrite_Point_distance(cymrite_Point point1, cymrite_Point point2);

bool cymrite_Point_collisionPoint(cymrite_Point point1, cymrite_Point point2);

bool cymrite_Point_collisionLine(cymrite_Point point, cymrite_Line line);

bool cymrite_Point_collisionCircle(cymrite_Point point, cymrite_Circle circle);

bool cymrite_Point_collisionRectangle(cymrite_Point point, cymrite_Rectangle rectangle);

bool cymrite_Line_compare(cymrite_Line line1, cymrite_Line line2);

double cymrite_Line_length(cymrite_Line line);

bool cymrite_Line_collisionPoint(cymrite_Line line, cymrite_Point point);

bool cymrite_Line_collisionLine(cymrite_Line line1, cymrite_Line line2);

bool cymrite_Line_collisionCircle(cymrite_Line line, cymrite_Circle circle);

bool cymrite_Line_collisionRectangle(cymrite_Line line, cymrite_Rectangle rectangle);

bool cymrite_Circle_compare(cymrite_Circle circle1, cymrite_Circle circle2);

double cymrite_Circle_area(cymrite_Circle circle);

double cymrite_Circle_circumference(cymrite_Circle circle);

bool cymrite_Circle_collisionPoint(cymrite_Circle circle, cymrite_Point point);

bool cymrite_Circle_collisionLine(cymrite_Circle circle, cymrite_Line line);

bool cymrite_Circle_collisionCircle(cymrite_Circle circle1, cymrite_Circle circle2);

bool cymrite_Circle_collisionRectangle(cymrite_Circle circle, cymrite_Rectangle rectangle);

bool cymrite_Rectangle_compare(cymrite_Rectangle rectangle1, cymrite_Rectangle rectangle2);

double cymrite_Rectangle_area(cymrite_Rectangle rectangle);

double cymrite_Rectangle_perimeter(cymrite_Rectangle rectangle);

bool cymrite_Rectangle_collisionPoint(cymrite_Rectangle rectangle, cymrite_Point point);

bool cymrite_Rectangle_collisionLine(cymrite_Rectangle rectangle, cymrite_Line line);

bool cymrite_Rectangle_collisionCircle(cymrite_Rectangle rectangle, cymrite_Circle circle);

bool cymrite_Rectangle_collisionRectangle(cymrite_Rectangle rectangle1, cymrite_Rectangle rectangle2);

#endif
