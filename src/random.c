#include <cymrite/random.h>
#include <stdlib.h>

void seedRandom(const int seed) {
	srand(seed);
}

double getRandom(const double min, const double max) {
	return (double)rand() / RAND_MAX * (max - min + 1) + min;
}
