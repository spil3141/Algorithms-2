#pragma once

#include <iostream>
#include <chrono>


namespace Utils {

	//<summary> Timer Class </summary> 
	class Timer
	{
	public:
		Timer()
		{
			m_StartTimepoint = std::chrono::high_resolution_clock::now();
		}
		~Timer()
		{
			auto endTimepoint = std::chrono::high_resolution_clock::now();

			auto start = std::chrono::time_point_cast<std::chrono::nanoseconds>(m_StartTimepoint).time_since_epoch().count();
			auto end = std::chrono::time_point_cast<std::chrono::nanoseconds>(endTimepoint).time_since_epoch().count();

			auto duration = (end - start) * 0.001f * 0.001f * 0.001f;
			double ms = (double)duration * 1000.0;

			std::cout << "	Time elapsed: " << ms << " ms" << std::endl;
		}

	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
	};

}