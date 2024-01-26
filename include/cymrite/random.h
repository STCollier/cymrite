#ifndef CYMRITE_HEADER_RANDOM
	#define CYMRITE_HEADER_RANDOM

void cymrite_setSeed(int seed);

void cymrite_setRandomSeed();

int cymrite_getRandom(const int minimum, const int maximum);

#endif
