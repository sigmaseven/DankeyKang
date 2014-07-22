#pragma once
#include <cstdint>

class PRNG
{
private:
	uint32_t seed;
	uint32_t old = 0;
	uint32_t iv = 31337;
public:
	void Seed(uint32_t seed);
	uint32_t Rand();
};