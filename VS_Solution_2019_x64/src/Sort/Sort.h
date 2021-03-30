#pragma once

#include "Utils/Common.h"
#include "Utils/Timer.h"
#include <vector>
#include <array>

namespace SP {
	namespace Algorithm {

		using namespace SP;
		using namespace Utility;

		// <summary> perform bubble sort on a list of elements </summary>
		// <para name="arr"> Unsorted list of element </para> 
		template<class T>
		void BubbleSort(std::vector<T>& arr)
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

		void Merge(std::vector<int>& arr, int start, int mid, int end)
		{
			// create a temp array to hold sorted sub-array
			std::vector<int> temp_arr;
			for (int i = 0; i < (end - start) + 1; i++)
				temp_arr.push_back(0);

			// crawlers for both intervals and for temp
			int i = start, j = mid + 1, k = 0;

			// traverse both arrays and in each iteration add smaller of both elements in temp 
			while (i <= mid && j <= end) {
				if (arr[i] <= arr[j]) {
					temp_arr[k] = arr[i];
					k += 1; i += 1;
				}
				else {
					temp_arr[k] = arr[j];
					k += 1; j += 1;
				}
			}

			// add elements left in the first interval 
			while (i <= mid) {
				temp_arr[k] = arr[i];
				k += 1; i += 1;
			}

			// add elements left in the second interval 
			while (j <= end) {
				temp_arr[k] = arr[j];
				k += 1; j += 1;
			}

			// copy temp to original interval
			for (i = start; i <= end; i += 1) {
				arr[i] = temp_arr[i - start];
			}
		}

		template<class T>
		static void MergeSort(std::vector<T>& arr, int start, int end)
		{
			if (start < end)
			{
				int mid = (start + end) / 2;
				MergeSort(arr, start, mid);
				MergeSort(arr, mid + 1, end);
				Merge(arr, start, mid, end);
			}

		}
}}