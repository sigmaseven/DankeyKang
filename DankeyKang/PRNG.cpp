#include "PRNG.h"

void PRNG::Seed(uint32_t newSeed)
{
	seed = newSeed;
}

uint32_t PRNG::Rand()
{
	uint32_t roll = seed * iv % 35565;
	seed = roll;
	return roll;
}