#include <cymrite/random.h>
#include <stdlib.h>

void cymrite_seedRandom(const int seed) {
	srand(seed);
}

double cymrite_getRandom(const double minimum, const double maximum) {
	return (double)rand() / RAND_MAX * (maximum - minimum + 1) + minimum;
}
