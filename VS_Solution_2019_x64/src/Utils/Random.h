#pragma once

#include <stdlib.h>
#include <time.h>

namespace Utils {

	class Random
	{
	public:
		static void Init();

		static int RandInt();
		static int RandInt(int from, int to);

	};
}