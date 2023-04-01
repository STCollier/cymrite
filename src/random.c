#include <cymrite/random.h>
#include <stdlib.h>

int seedRandom(const unsigned int seed) {
	srand(seed);
	return 0;
}

int getRandom(const int min, const int max) {
	return rand() / RAND_MAX * (max - min + 1) + min;
}

double getRandom(const double min, const double max) {
	return (double)rand() / RAND_MAX * (max - min + 1) + min;
}
