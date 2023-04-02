#include <cymrite/random.h>
#include <stdlib.h>

void seedRandom(const int seed) {
	srand(seed);
}

int getRandom(const int min, const int max) {
	return rand() / RAND_MAX * (max - min + 1) + min;
}

double getRandom(const double min, const double max) {
	return (double)rand() / RAND_MAX * (max - min + 1) + min;
}
