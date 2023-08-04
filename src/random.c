#include <stdlib.h>
#include <time.h>
#include "../include/cymrite/random.h"

void cymrite_setSeed(const int seed) {
	srand(seed);
}

void cymrite_setRandomSeed() {
	srand(time(NULL));
}

int cymrite_getRandom(const int minimum, const int maximum) {
	return rand() % (maximum + 1 - minimum) + minimum;
}
