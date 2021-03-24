#pragma once

namespace SP { namespace Utility {

		// <summary> Swap two numbers </summary>
		// <para name="a"> Element a </para> 
		// <para name="b"> Element b </para> 
		inline void Swap(int& a, int& b)
		{
			int temp = a;
			a = b;
			b = temp;
		}


}}