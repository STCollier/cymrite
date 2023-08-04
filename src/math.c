#include <float.h>
#include <math.h>
#include <stdbool.h>
#include "../include/cymrite/math.h"

double cymrite_clamp(const double value, const double limit1, const double limit2) {
	const double minimum = fmin(limit1, limit2);
	const double maximum = fmax(limit1, limit2);
	return (value < minimum) ? minimum : ((value > maximum) ? maximum : value);
}

bool cymrite_almostEqual(const double value1, const double value2) {
	return fabs(value1 - value2) <= DBL_EPSILON;
}