#include <math.h>
#include <stdbool.h>
#include "../include/cymrite/geometry.h"
#include "../include/cymrite/math.h"

cymrite_Point cymrite_Point_create(const double x, const double y) {
	cymrite_Point point;
	point.x = x;
	point.y = y;
	return point;
}

bool cymrite_Point_compare(const cymrite_Point point1, const cymrite_Point point2) {
	return cymrite_almostEqual(point1.x, point2.x) && cymrite_almostEqual(point1.y, point2.y);
}

double cymrite_Point_distance(const cymrite_Point point1, const cymrite_Point point2) {
	return hypot(point1.x - point2.x, point1.y - point2.y);
}

bool cymrite_Point_collisionPoint(const cymrite_Point point1, const cymrite_Point point2) {
	return cymrite_Point_compare(point1, point2);
}

bool cymrite_Point_collisionLine(const cymrite_Point point, const cymrite_Line line) {
	return cymrite_almostEqual(cymrite_Point_distance(point, line.start) + cymrite_Point_distance(point, line.end), cymrite_Line_length(line));
}

bool cymrite_Point_collisionCircle(cymrite_Point point, cymrite_Circle circle) {
	return (cymrite_Point_distance(point, circle.center) <= circle.radius);
}

bool cymrite_Point_collisionRectangle(cymrite_Point point, cymrite_Rectangle rectangle) {
	return ((point.x >= rectangle.position.x)
			&& (point.x <= rectangle.position.x + rectangle.size.x)
			|| (point.x <= rectangle.position.x)
			&& (point.x >= rectangle.position.x + rectangle.size.x))
		&& ((point.y >= rectangle.position.y)
			&& (point.y <= rectangle.position.y + rectangle.size.y)
			|| (point.y <= rectangle.position.y)
			&& (point.y >= rectangle.position.y + rectangle.size.y));
}

cymrite_Line cymrite_Line_create(const cymrite_Point start, const cymrite_Point end) {
	cymrite_Line line;
	line.start = start;
	line.end = end;
	return line;
}

bool cymrite_Line_compare(const cymrite_Line line1, const cymrite_Line line2) {
	return cymrite_Point_compare(line1.start, line2.start) && cymrite_Point_compare(line1.end, line2.end) || cymrite_Point_compare(line1.end, line2.start) && cymrite_Point_compare(line1.start, line2.end);
}

bool cymrite_Line_length(const cymrite_Line line) {
	return cymrite_Point_distance(line.start, line.end);
}

bool cymrite_Line_collisionPoint(const cymrite_Line line, const cymrite_Point point) {
	return cymrite_Point_collisionLine(point, line);
}

bool cymrite_Line_collisionLine(cymrite_Line line1, cymrite_Line line2) {
	// not even going to touch this
	double uA = ((line2.end.x-line2.start.x)*(line1.start.y-line2.start.y) - (line2.end.y-line2.start.y)*(line1.start.x-line2.start.x)) / ((line2.end.y-line2.start.y)*(line1.end.x-line1.start.x) - (line2.end.x-line2.start.x)*(line1.end.y-line1.start.y));
	double uB = ((line1.end.x-line1.start.x)*(line1.start.y-line2.start.y) - (line1.end.y-line1.start.y)*(line1.start.x-line2.start.x)) / ((line2.end.y-line2.start.y)*(line1.end.x-line1.start.x) - (line2.end.x-line2.start.x)*(line1.end.y-line1.start.y));
	return (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1);
}

bool cymrite_Line_collisionCircle(const cymrite_Line line, const cymrite_Circle circle) {	
	if (cymrite_Point_collisionCircle(line.start, circle) || cymrite_Point_collisionCircle(line.end, circle)) {
		return true;
	}
	double lineLength = cymrite_Line_length(line);
	double dot = (((circle.x - line.start.x) * (line.end.x-line.start.x)) + ((circle.y-line.start.y) * (line.end.y-line.start.y))) / (lineLength * lineLength);
	double closestX = line.start.x + (dot * (line.end.x - line.start.x));
	double closestY = line.start.y + (dot * (line.end.y - line.start.y));
	return cymrite_Line_collisionPoint(line, cymrite_Point_create(closestX, closestY)) && (cymrite_Point_distance(cymrite_Point_create(closestX, circle.x), cymrite_Point_create(closestY, circle.y)) <= circle.radius);
}

bool cymrite_Line_collisionRectangle(const cymrite_Line line, const cymrite_Rectangle rectangle) {
	const cymrite_Point point1 = rectangle.position;
	const cymrite_Point point2 = cymrite_Point_create(rectangle.position.x + rectangle.size.x, rectangle.position.y);
	const cymrite_Point point3 = cymrite_Point_create(rectangle.position.x + rectangle.size.x, rectangle.position.y + rectangle.size.y);
	const cymrite_Point point4 = cymrite_Point_create(rectangle.position.x, rectangle.position.y + rectangle.size.y);
	return cymrite_Line_collisionLine(line, cymrite_Line_create(point1, point2))
		|| cymrite_Line_collisionLine(line, cymrite_Line_create(point2, point3))
		|| cymrite_Line_collisionLine(line, cymrite_Line_create(point3, point4))
		|| cymrite_Line_collisionLine(line, cymrite_Line_create(point4, point1));
}

cymrite_Circle cymrite_Circle_create(const cymrite_Point center, const double radius) {
	cymrite_Circle circle;
	circle.center = center;
	circle.radius = radius;
	return circle;
}

bool cymrite_Circle_compare(const cymrite_Circle circle1, const cymrite_Circle circle2) {
	return cymrite_Point_compare(circle1.center, circle2.center) && cymrite_almostEqual(circle1.radius, circle2.radius);
}

double cymrite_Circle_area(const cymrite_Circle circle) {
	return CYMRITE_PI * circle.radius * circle.radius;
}

double cymrite_Circle_circumference(const cymrite_Circle circle) {
	return CYMRITE_TAU * circle.radius;

bool cymrite_Circle_collisionPoint(const cymrite_Circle circle, const cymrite_Point point) {
	return cymrite_Point_collisionCircle(point, circle);
}

bool cymrite_Circle_collisionLine(const cymrite_Circle circle, const cymrite_Line line) {
	return cymrite_Line_collisionCircle(line, circle);
}

bool cymrite_Circle_collisionCircle(const cymrite_Circle circle1, const cymrite_Circle circle2) {
	return (cymrite_Point_distance(circle1.center, circle2.center) <= circle1.radius + circle2.radius);
}

bool cymrite_Circle_collisionRectangle(const cymrite_Circle circle, const cymrite_Rectangle rectangle) {
	return cymrite_Point_collisionCircle(cymrite_Point_create(cymrite_clamp(circle.center.x, rectangle.position.x, rectangle.position.x + rectangle.size.x), cymrite_clamp(circle.center.y, rectangle.position.y, rectangle.position.y + rectangle.size.y)), circle);
}

cymrite_Rectangle cymrite_Rectangle_create(const cymrite_Point position, const cymrite_Vector2 size) {
	cymrite_Rectangle rectangle;
	rectangle.position = position;
	rectangle.size = size;
	return rectangle;
}

bool cymrite_Rectangle_compare(const cymrite_Rectangle rectangle1, const cymrite_Rectangle rectangle2) {
	// too lazy to implement algorithm so raw logic it is!
	const cymrite_Point point1 = rectangle1.position;
	const cymrite_Point point2 = cymrite_Point_create(rectangle1.position.x + rectangle1.size.x, rectangle1.position.y);
	const cymrite_Point point3 = cymrite_Point_create(rectangle1.position.x + rectangle1.size.x, rectangle1.position.y + rectangle1.size.y);
	const cymrite_Point point4 = cymrite_Point_create(rectangle1.position.x, rectangle1.position.y + rectangle1.size.y);
	const cymrite_Point point5 = rectangle2.position;
	const cymrite_Point point6 = cymrite_Point_create(rectangle2.position.x + rectangle2.size.x, rectangle2.position.y);
	const cymrite_Point point7 = cymrite_Point_create(rectangle2.position.x + rectangle2.size.x, rectangle2.position.y + rectangle2.size.y);
	const cymrite_Point point8 = cymrite_Point_create(rectangle2.position.x, rectangle2.position.y + rectangle2.size.y);
	return cymrite_Point_compare(point1, point5)
		&& cymrite_Point_compare(point2, point6)
		&& cymrite_Point_compare(point3, point7)
		&& cymrite_Point_compare(point4, point8)
		|| cymrite_Point_compare(point2, point5)
		&& cymrite_Point_compare(point3, point6)
		&& cymrite_Point_compare(point4, point7)
		&& cymrite_Point_compare(point1, point8)
		|| cymrite_Point_compare(point3, point5)
		&& cymrite_Point_compare(point4, point6)
		&& cymrite_Point_compare(point1, point7)
		&& cymrite_Point_compare(point2, point8)
		|| cymrite_Point_compare(point4, point5)
		&& cymrite_Point_compare(point1, point6)
		&& cymrite_Point_compare(point2, point7)
		&& cymrite_Point_compare(point3, point8)
		|| cymrite_Point_compare(point4, point5)
		&& cymrite_Point_compare(point3, point6)
		&& cymrite_Point_compare(point2, point7)
		&& cymrite_Point_compare(point1, point8)
		|| cymrite_Point_compare(point3, point5)
		&& cymrite_Point_compare(point2, point6)
		&& cymrite_Point_compare(point1, point7)
		&& cymrite_Point_compare(point4, point8)
		|| cymrite_Point_compare(point2, point5)
		&& cymrite_Point_compare(point1, point6)
		&& cymrite_Point_compare(point4, point7)
		&& cymrite_Point_compare(point3, point8)
		|| cymrite_Point_compare(point1, point5)
		&& cymrite_Point_compare(point4, point6)
		&& cymrite_Point_compare(point3, point7)
		&& cymrite_Point_compare(point2, point8);
}

double cymrite_Rectangle_area(const cymrite_Rectangle rectangle) {
	return rectangle.size.x * rectangle.size.y;
}

double cymrite_Rectangle_perimeter(const cymrite_Rectangle rectangle) {
	const cymrite_Point point1 = rectangle.position;
	const cymrite_Point point2 = cymrite_Point_create(rectangle.position.x + rectangle.size.x, rectangle.position.y);
	const cymrite_Point point3 = cymrite_Point_create(rectangle.position.x + rectangle.size.x, rectangle.position.y + rectangle.size.y);
	const cymrite_Point point4 = cymrite_Point_create(rectangle.position.x, rectangle.position.y + rectangle.size.y);
	return cymrite_Point_distance(point1, point2)
		+ cymrite_Point_distance(point2, point3)
		+ cymrite_Point_distance(point3, point4)
		+ cymrite_Point_distance(point4, point1);
}

bool cymrite_Rectangle_collisionPoint(const cymrite_Rectangle rectangle, const cymrite_Point point) {
	return cymrite_Point_collisionRectangle(point, rectangle);
}

bool cymrite_Rectangle_collisionLine(const cymrite_Rectangle rectangle, const cymrite_Line line) {
	return cymrite_Line_collisionRectangle(line, rectangle);
}

bool cymrite_Rectangle_collisionCircle(const cymrite_Rectangle rectangle, const cymrite_Circle circle) {
	return cymrite_Circle_collisionRectangle(circle, rectangle);
}

bool cymrite_Rectangle_collisionRectangle(cymrite_Rectangle rectangle1, cymrite_Rectangle rectangle2) {
	const cymrite_Point point1 = rectangle1.position;
	const cymrite_Point point2 = cymrite_Point_create(rectangle1.position.x + rectangle1.size.x, rectangle1.position.y);
	const cymrite_Point point3 = cymrite_Point_create(rectangle1.position.x + rectangle1.size.x, rectangle1.position.y + rectangle1.size.y);
	const cymrite_Point point4 = cymrite_Point_create(rectangle1.position.x, rectangle1.position.y + rectangle1.size.y);
	const cymrite_Point point5 = rectangle2.position;
	const cymrite_Point point6 = cymrite_Point_create(rectangle2.position.x + rectangle2.size.x, rectangle2.position.y);
	const cymrite_Point point7 = cymrite_Point_create(rectangle2.position.x + rectangle2.size.x, rectangle2.position.y + rectangle2.size.y);
	const cymrite_Point point8 = cymrite_Point_create(rectangle2.position.x, rectangle2.position.y + rectangle2.size.y);
	const cymrite_Line line1 = cymrite_Line_create(point1, point2);
	const cymrite_Line line2 = cymrite_Line_create(point2, point3);
	const cymrite_Line line3 = cymrite_Line_create(point3, point4);
	const cymrite_Line line4 = cymrite_Line_create(point4, point1);
	const cymrite_Line line5 = cymrite_Line_create(point5, point6);
	const cymrite_Line line6 = cymrite_Line_create(point6, point7);
	const cymrite_Line line7 = cymrite_Line_create(point7, point8);
	const cymrite_Line line8 = cymrite_Line_create(point8, point1);
	return cymrite_Line_collisionLine(line1, line5)
		|| cymrite_Line_collisionLine(line2, line5)
		|| cymrite_Line_collisionLine(line3, line5)
		|| cymrite_Line_collisionLine(line4, line5)
		|| cymrite_Line_collisionLine(line1, line6)
		|| cymrite_Line_collisionLine(line2, line6)
		|| cymrite_Line_collisionLine(line3, line6)
		|| cymrite_Line_collisionLine(line4, line6)
		|| cymrite_Line_collisionLine(line1, line7)
		|| cymrite_Line_collisionLine(line2, line7)
		|| cymrite_Line_collisionLine(line3, line7)
		|| cymrite_Line_collisionLine(line4, line7)
		|| cymrite_Line_collisionLine(line1, line8)
		|| cymrite_Line_collisionLine(line2, line8)
		|| cymrite_Line_collisionLine(line3, line8)
		|| cymrite_Line_collisionLine(line4, line8);
}
