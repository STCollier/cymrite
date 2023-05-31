#include <cymrite/geometry.h>
#include <stdbool.h>
#include <math.h>

float cymrite_dist(cymrite_Line line) {
	return (sqrt(pow(line.x1 - line.x2, 2) + pow(line.y1 - line.y2, 2)));
}

bool cymrite_pointPoint(cymrite_Point point1, cymrite_Point point2) {
	return (point1.x == point2.x && point1.y == point2.y);
}

bool cymrite_pointCircle(cymrite_Point point, cymrite_Circle circle) {
	float distX = point.x - circle.x;
	float distY = point.y - circle.y;

	float distance = sqrt((distX*distX) + (distY*distY));

	return (distance < circle.radius);
}

bool cymrite_circleCircle(cymrite_Circle circle1, cymrite_Circle circle2) {
	float distX = circle1.x - circle2.x;
	float distY = circle1.y - circle2.y;

	float distance = sqrt((distX*distX) + (distY*distY));

	return (distance <= circle1.radius + circle2.radius);
}

bool cymrite_pointRectangle(cymrite_Point point, cymrite_Rectangle rectangle) {
	return (point.x >= rectangle.x &&
    		point.x <= rectangle.x + rectangle.width &&
   			point.y >= rectangle.y &&
   			point.y <= rectangle.y + rectangle.height);
}

bool cymrite_rectangleRectangle(cymrite_Rectangle rectangle1, cymrite_Rectangle rectangle2) {
	return (rectangle1.x + rectangle1.width >= rectangle2.x &&
	  		rectangle1.x <= rectangle2.x + rectangle2.width &&
	  		rectangle1.y + rectangle1.height >= rectangle2.y &&
	  		rectangle1.y <= rectangle2.y + rectangle2.height);
}

bool cymrite_circleRectangle(cymrite_Circle circle, cymrite_Rectangle rectangle) {
	float testX = circle.x;
	float testY = circle.y;

	if (circle.x < rectangle.x) testX = rectangle.x;
	else if (circle.x > rectangle.x + rectangle.width) testX = rectangle.x + rectangle.width;
	if (circle.y < rectangle.y) testY = rectangle.y;
	else if (circle.y > rectangle.y + rectangle.height) testY = rectangle.y + rectangle.height;

	float distX = circle.x - testX;
	float distY = circle.y - testY;
	float distance = sqrt((distX*distX) + (distY*distY));

	return (distance <= circle.radius);
}

bool cymrite_linePoint(cymrite_Line line, cymrite_Point point) {
	float lineLength = cymrite_dist(line);

	cymrite_Line a = {point.x, point.y, line.x1, line.y1};
	cymrite_Line b = {point.x, point.y, line.x2, line.y2};

	float d1 = cymrite_dist(a);
	float d2 = cymrite_dist(b);

	return (d1+d2 >= lineLength && d1+d2 <= lineLength);
}

bool cymrite_lineCircle(cymrite_Line line, cymrite_Circle circle) {
	cymrite_Point a = {line.x1, line.y2};
	cymrite_Point b = {line.x2, line.y2};

	bool inside1 = cymrite_pointCircle(a, circle);
  	bool inside2 = cymrite_pointCircle(b, circle);	
  	if (inside1 || inside2) return true;

  	float lineLength = cymrite_dist(line);
  	float dot = (((circle.x - line.x1) * (line.x2-line.x1)) + ((circle.y-line.y1) * (line.y2-line.y1))) / pow(lineLength, 2);

  	float closestX = line.x1 + (dot * (line.x2 - line.x1));
	float closestY = line.y1 + (dot * (line.y2 - line.y1));

	cymrite_Point p = {closestX, closestY};
	bool onSegment = cymrite_linePoint(line, p);
	if (!onSegment) return false;

	cymrite_Line d = {closestX, circle.x, closestY, circle.y};
	float distance = cymrite_dist(d);

	return (distance <= circle.radius);
}

bool cymrite_lineLine(cymrite_Line line1, cymrite_Line line2) {
	float uA = ((line2.x2-line2.x1)*(line1.y1-line2.y1) - (line2.y2-line2.y1)*(line1.x1-line2.x1)) / ((line2.y2-line2.y1)*(line1.x2-line1.x1) - (line2.x2-line2.x1)*(line1.y2-line1.y1));
	float uB = ((line1.x2-line1.x1)*(line1.y1-line2.y1) - (line1.y2-line1.y1)*(line1.x1-line2.x1)) / ((line2.y2-line2.y1)*(line1.x2-line1.x1) - (line2.x2-line2.x1)*(line1.y2-line1.y1));

	return (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1);
}

bool cymrite_lineRectangle(cymrite_Line line, cymrite_Rectangle rectangle) {
	cymrite_Line l = {rectangle.x, rectangle.y, rectangle.x, rectangle.y + rectangle.height};
	cymrite_Line r = {rectangle.x + rectangle.width, rectangle.y, rectangle.x + rectangle.width, rectangle.y};
	cymrite_Line t = {rectangle.x, rectangle.y, rectangle.x + rectangle.width, rectangle.y};
	cymrite_Line b = {rectangle.x, rectangle.y + rectangle.height, rectangle.x + rectangle.width, rectangle.y + rectangle.height};

	bool left = cymrite_lineLine(line, l);
	bool right = cymrite_lineLine(line, r);
	bool top = cymrite_lineLine(line, t);
	bool bottom = cymrite_lineLine(line, b);

	return (left || right || top || bottom);
}