#include <math.h>
#include <stdbool.h>
#include "../include/cymrite/geometry.h"
#include "../include/cymrite/math.h"

static bool cymrite_Point_compare(const cymrite_Point point1, const cymrite_Point point2) {
	return cymrite_almostEqual(point1.x, point2.x) && cymrite_almostEqual(point1.y, point2.y);
}

double cymrite_Point_distance(const cymrite_Point point1, const cymrite_Point point2) {
	return hypot(point1.x - point2.x, point1.y - point2.y);
}

bool cymrite_Point_collisionPoint(const cymrite_Point point1, const cymrite_Point point2) {
	return cymrite_Point_compare(point1, point2);
}

bool cymrite_Point_collisionLine(const cymrite_Point point, const cymrite_Line line) {
	return cymrite_almostEqual(cymrite_Point_distance(point, (cymrite_Point){line.x1, line.y1}) + cymrite_Point_distance(point, (cymrite_Point){line.x2, line.y2}), cymrite_Line_length(line));
}

bool cymrite_Point_collisionCircle(cymrite_Point point, cymrite_Circle circle) {
	return (cymrite_Point_distance(point, (cymrite_Point){circle.x, circle.y}) <= circle.radius);
}

bool cymrite_Point_collisionRectangle(cymrite_Point point, cymrite_Rectangle rectangle) {
	return ((point.x >= rectangle.x)
			&& ((point.x <= rectangle.x + rectangle.width)
			|| ((point.x <= rectangle.x)
			&& (point.x >= rectangle.x + rectangle.width)))
		&& (((point.y >= rectangle.y)
			&& ((point.y <= rectangle.y + rectangle.height)))
			|| ((point.y <= rectangle.y)
			&& (point.y >= rectangle.y + rectangle.height))));
}

bool cymrite_Line_compare(const cymrite_Line line1, const cymrite_Line line2) {
	return (cymrite_Point_compare((cymrite_Point){line1.x1, line1.y1}, (cymrite_Point){line2.x1, line2.y1}) && cymrite_Point_compare((cymrite_Point){line1.x2, line1.y2}, (cymrite_Point){line2.x2, line2.y2})) || (cymrite_Point_compare((cymrite_Point){line1.x2, line1.y2}, (cymrite_Point){line2.x1, line2.y1}) && cymrite_Point_compare((cymrite_Point){line1.x1, line1.y1}, (cymrite_Point){line2.x2, line2.y2}));
}

double cymrite_Line_length(const cymrite_Line line) {
	return cymrite_Point_distance((cymrite_Point){line.x1, line.y1}, (cymrite_Point){line.x2, line.y2});
}

bool cymrite_Line_collisionPoint(const cymrite_Line line, const cymrite_Point point) {
	return cymrite_Point_collisionLine(point, line);
}

bool cymrite_Line_collisionLine(cymrite_Line line1, cymrite_Line line2) {
	// not even going to touch this
	double uA = ((line2.x2-line2.x1)*(line1.y1-line2.y1) - (line2.y2-line2.y1)*(line1.x1-line2.x1)) / ((line2.y2-line2.y1)*(line1.x2-line1.x1) - (line2.x2-line2.x1)*(line1.y2-line1.y1));
	double uB = ((line1.x2-line1.x1)*(line1.y1-line2.y1) - (line1.y2-line1.y1)*(line1.x1-line2.x1)) / ((line2.y2-line2.y1)*(line1.x2-line1.x1) - (line2.x2-line2.x1)*(line1.y2-line1.y1));
	return (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1);
}

bool cymrite_Line_collisionCircle(const cymrite_Line line, const cymrite_Circle circle) {	
	if (cymrite_Point_collisionCircle((cymrite_Point){line.x1, line.y1}, circle) || cymrite_Point_collisionCircle((cymrite_Point){line.x2, line.y2}, circle)) {
		return true;
	}
	double lineLength = cymrite_Line_length(line);
	double dot = (((circle.x - line.x1) * (line.x2-line.x1)) + ((circle.y-line.y1) * (line.y2-line.y1))) / (lineLength * lineLength);
	double closestX = line.x1 + (dot * (line.x2 - line.x1));
	double closestY = line.y1 + (dot * (line.y2 - line.y1));
	return cymrite_Line_collisionPoint(line, (cymrite_Point){closestX, closestY}) && (cymrite_Point_distance((cymrite_Point){closestX, circle.x}, (cymrite_Point){closestY, circle.y}) <= circle.radius);
}

bool cymrite_Line_collisionRectangle(const cymrite_Line line, const cymrite_Rectangle rectangle) {
	const cymrite_Point point1 = {rectangle.x, rectangle.y};
	const cymrite_Point point2 = {rectangle.x + rectangle.width, rectangle.y};
	const cymrite_Point point3 = {rectangle.x + rectangle.width, rectangle.y + rectangle.height};
	const cymrite_Point point4 = {rectangle.x, rectangle.y + rectangle.height};
	return cymrite_Line_collisionLine(line, (cymrite_Line){point1.x, point1.y, point2.x, point2.y})
		|| cymrite_Line_collisionLine(line, (cymrite_Line){point2.x, point2.y, point3.x, point3.y})
		|| cymrite_Line_collisionLine(line, (cymrite_Line){point3.x, point3.y, point4.x, point4.y})
		|| cymrite_Line_collisionLine(line, (cymrite_Line){point4.x, point4.y, point1.x, point1.y});
}

bool cymrite_Circle_compare(const cymrite_Circle circle1, const cymrite_Circle circle2) {
	return cymrite_Point_compare((cymrite_Point){circle1.x, circle1.y}, (cymrite_Point){circle2.x, circle2.y}) && cymrite_almostEqual(circle1.radius, circle2.radius);
}

double cymrite_Circle_area(const cymrite_Circle circle) {
	return CYMRITE_PI * circle.radius * circle.radius;
}

double cymrite_Circle_circumference(const cymrite_Circle circle) {
	return CYMRITE_TAU * circle.radius;
}

bool cymrite_Circle_collisionPoint(const cymrite_Circle circle, const cymrite_Point point) {
	return cymrite_Point_collisionCircle(point, circle);
}

bool cymrite_Circle_collisionLine(const cymrite_Circle circle, const cymrite_Line line) {
	return cymrite_Line_collisionCircle(line, circle);
}

bool cymrite_Circle_collisionCircle(const cymrite_Circle circle1, const cymrite_Circle circle2) {
	return (cymrite_Point_distance((cymrite_Point){circle1.x, circle1.y}, (cymrite_Point){circle2.x, circle2.y}) <= circle1.radius + circle2.radius);
}

bool cymrite_Circle_collisionRectangle(const cymrite_Circle circle, const cymrite_Rectangle rectangle) {
	return cymrite_Point_collisionCircle((cymrite_Point){cymrite_clamp(circle.x, rectangle.x, rectangle.x + rectangle.width), cymrite_clamp(circle.y, rectangle.y, rectangle.y + rectangle.height)}, circle);
}

bool cymrite_Rectangle_compare(const cymrite_Rectangle rectangle1, const cymrite_Rectangle rectangle2) {
	// Raw logic monstrosity (Credit: Eczbek)
	const cymrite_Point point1 = {rectangle1.x, rectangle1.y};
	const cymrite_Point point2 = {rectangle1.x + rectangle1.width, rectangle1.y};
	const cymrite_Point point3 = {rectangle1.x + rectangle1.width, rectangle1.y + rectangle1.height};
	const cymrite_Point point4 = {rectangle1.x, rectangle1.y + rectangle1.height};
	const cymrite_Point point5 = {rectangle2.x, rectangle2.y};
	const cymrite_Point point6 = {rectangle2.x + rectangle2.width, rectangle2.y};
	const cymrite_Point point7 = {rectangle2.x + rectangle2.width, rectangle2.y + rectangle2.height};
	const cymrite_Point point8 = {rectangle2.x, rectangle2.y + rectangle2.height};
	return (cymrite_Point_compare(point1, point5)
		&& cymrite_Point_compare(point2, point6)
		&& cymrite_Point_compare(point3, point7)
		&& cymrite_Point_compare(point4, point8))
		|| (cymrite_Point_compare(point2, point5)
		&& cymrite_Point_compare(point3, point6)
		&& cymrite_Point_compare(point4, point7)
		&& cymrite_Point_compare(point1, point8))
		|| (cymrite_Point_compare(point3, point5)
		&& cymrite_Point_compare(point4, point6)
		&& cymrite_Point_compare(point1, point7)
		&& cymrite_Point_compare(point2, point8))
		|| (cymrite_Point_compare(point4, point5)
		&& cymrite_Point_compare(point1, point6)
		&& cymrite_Point_compare(point2, point7)
		&& cymrite_Point_compare(point3, point8))
		|| (cymrite_Point_compare(point4, point5)
		&& cymrite_Point_compare(point3, point6)
		&& cymrite_Point_compare(point2, point7)
		&& cymrite_Point_compare(point1, point8))
		|| (cymrite_Point_compare(point3, point5)
		&& cymrite_Point_compare(point2, point6)
		&& cymrite_Point_compare(point1, point7)
		&& cymrite_Point_compare(point4, point8))
		|| (cymrite_Point_compare(point2, point5)
		&& cymrite_Point_compare(point1, point6)
		&& cymrite_Point_compare(point4, point7)
		&& cymrite_Point_compare(point3, point8))
		|| (cymrite_Point_compare(point1, point5)
		&& cymrite_Point_compare(point4, point6)
		&& cymrite_Point_compare(point3, point7)
		&& cymrite_Point_compare(point2, point8));
}

double cymrite_Rectangle_area(const cymrite_Rectangle rectangle) {
	return rectangle.width * rectangle.height;
}

double cymrite_Rectangle_perimeter(const cymrite_Rectangle rectangle) {
	const cymrite_Point point1 = {rectangle.x, rectangle.y};
	const cymrite_Point point2 = {rectangle.x + rectangle.width, rectangle.y};
	const cymrite_Point point3 = {rectangle.x + rectangle.width, rectangle.y + rectangle.height};
	const cymrite_Point point4 = {rectangle.x, rectangle.y + rectangle.height};
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
	const cymrite_Point point1 = {rectangle1.x, rectangle1.y};
	const cymrite_Point point2 = {rectangle1.x + rectangle1.width, rectangle1.y};
	const cymrite_Point point3 = {rectangle1.x + rectangle1.width, rectangle1.y + rectangle1.height};
	const cymrite_Point point4 = {rectangle1.x, rectangle1.y + rectangle1.height};
	const cymrite_Point point5 = {rectangle2.x, rectangle2.y};
	const cymrite_Point point6 = {rectangle2.x + rectangle2.width, rectangle2.y};
	const cymrite_Point point7 = {rectangle2.x + rectangle2.width, rectangle2.y + rectangle2.height};
	const cymrite_Point point8 = {rectangle2.x, rectangle2.y + rectangle2.height};
	const cymrite_Line line1 = {point1.x, point1.y, point2.x, point2.y};
	const cymrite_Line line2 = {point2.x, point2.y, point3.x, point3.y};
	const cymrite_Line line3 = {point3.x, point3.y, point4.x, point4.y};
	const cymrite_Line line4 = {point4.x, point4.y, point1.x, point1.y};
	const cymrite_Line line5 = {point5.x, point5.y, point6.x, point6.y};
	const cymrite_Line line6 = {point6.x, point6.y, point7.x, point7.y};
	const cymrite_Line line7 = {point7.x, point7.y, point8.x, point8.y};
	const cymrite_Line line8 = {point8.x, point8.y, point1.x, point1.y};
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
