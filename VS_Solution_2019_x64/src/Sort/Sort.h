#pragma once

#include "Utils/Common.h"
#include "Utils/Timer.h"
#include <vector>

namespace SP {
	namespace Algorithm {

		using namespace SP;
		using namespace Utility;

		// <summary> perform bubble sort on a list of elements </summary>
		// <para name="arr"> Unsorted list of element </para> 
		void BubbleSort(std::vector<int>& arr)
		{
			std::cout << "Bubble Sort: " << std::endl;
			Timer timer;

			for (int i = 0; i < arr.size(); i++)
			{
				for (int j = 0; j < (arr.size()-1) - i; j++)
				{
					if (arr[j] > arr[j+1])
						Swap(arr[j], arr[j + 1]);
				}
			}
		}

		// <summary> perform bubble sort on a list of elements </summary>
		// <para name="arr"> Unsorted list of element </para> 
		// <para name="arr"> Unsorted list of element </para> 
		void BubbleSort(int arr[], int N)
		{
			std::cout << "Bubble Sort: " << std::endl;
			Timer timer;

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < (N-1)-i; j++)
				{
					if (arr[j] > arr[j + 1])
						Swap(arr[j], arr[j + 1]);
				}
			}
		}

		// <summary> Sorts a list of integers using selection sort </summary>
		// <para name="arr"> Unsorted list of element : vector of integers </para> 
		void SelectionSort(std::vector<int>& arr)
		{
			std::cout << "Selection Sort: vector class" << std::endl;
			Timer timer;
			int N = arr.size();
			for (int i = 0; i < arr.size(); i++)
			{
				int* min = &arr[i];
				for (int j = i + 1; j < arr.size(); j++)
				{
					if (arr[j] < *min)
						min = &arr[j];
				}

				Swap(arr[i], *min);
			}
		}

		void SelectionSort(int arr[], int N)
		{
			std::cout << "Selection Sort: native array " << std::endl;
			Timer timer;
			for (int i = 0; i < N; i++)
			{
				int* min = &arr[i];
				for (int j = i + 1; j < N; j++)
				{
					if (arr[j] < *min)
						min = &arr[j];
				}

				Swap(arr[i], *min);
			}
		}

		void selectionSort(int arr[], int n)
		{
			std::cout << "Selection Sort: (Third-party implementation) " << std::endl;
			Timer timer;
			int i, j, min_idx;

			// One by one move boundary of unsorted sub-array 
			for (i = 0; i < n - 1; i++)
			{
				// Find the minimum element in unsorted array 
				min_idx = i;
				for (j = i + 1; j < n; j++)
					if (arr[j] < arr[min_idx])
						min_idx = j;

				// Swap the found minimum element with the first element 
				Swap(arr[min_idx], arr[i]);
			}
		}

		void InsertionSort(int arr[], int N)
		{
			std::cout << "Insertion Sort:" << std::endl;
			Timer timer;
			int index;

			for (int i = 0; i < N-1; i++)
			{
				index = i;
				while (arr[index] > arr[index + 1])
				{
					Swap(arr[index], arr[index + 1]);
					index--;
				}
			}
		}
}}