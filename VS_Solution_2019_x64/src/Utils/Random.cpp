#include "Random.h"

namespace Utils {

	static time_t s_Time;

	void Random::Init()
	{
		//initialize rand seed
		srand((unsigned) time(NULL));
	}

	int Random::RandInt()
	{
		return rand() % 100000;
	}

	int Random::RandInt(int from, int to)
	{
		//TODO: Implementation needed
		return rand() % 1000;
	}
}