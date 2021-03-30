#pragma once

namespace SP { namespace Utility {

		// <summary> Swap two numbers </summary>
		// <para name="a"> Element a </para> 
		// <para name="b"> Element b </para> 
		template<typename T>
		inline void Swap(T& a, T& b)
		{
			T temp = a;
			a = b;
			b = temp;
		}


}}