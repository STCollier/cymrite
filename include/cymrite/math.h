#ifndef CYMRITE_HEADER_MATH
#	define CYMRITE_HEADER_MATH

#	include <math.h>
#	include <stdbool.h>

#	define CYMRITE_PI acos(-1)
#	define CYMRITE_TAU (CYMRITE_PI * 2)
#	define CYMRITE_MIN(a, b) (((a) < (b)) ? (a) : (b))
#	define CYMRITE_MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef struct {
	double x;
	double y;
} cymrite_Vector2;

typedef struct {
	double x;
	double y;
	double z;
} cymrite_Vector3;

double cymrite_clamp(double value, double minimum, double maximum);

bool cymrite_almostEqual(double value1, double value2);

#endif
