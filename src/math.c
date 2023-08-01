#include <float.h>
#include <math.h>
#include <stdbool.h>
#include "../include/cymrite/math.h"

cymrite_Vector2 cymrite_Vector2_create(double x, double y) {
	cymrite_Vector2 vector2;
	vector2.x = x;
	vector2.y = y;
	return vector2;
}

cymrite_Vector3 cymrite_Vector3_create(double x, double y, double z) {
	cymrite_Vector3 vector3;
	vector3.x = x;
	vector3.y = y;
	vector3.z = z;
	return vector3;
}

double cymrite_clamp(const double value, const double limit1, const double limit2) {
	const double minimum = fmin(limit1, limit2);
	const double maximum = fmax(limit1, limit2);
	return (value < minimum) ? minimum : ((value > maximum) ? maximum : value);
}

bool cymrite_almostEqual(const double value1, const double value2) {
	return fabs(value1 - value2) <= DBL_EPSILON;
}
