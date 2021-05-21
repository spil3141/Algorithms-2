#pragma once

#include <vector>

namespace Algorithm {

	class Sorter
	{
	public:
		Sorter() = default;
		~Sorter() = default;

		void BubbleSort(int arr[], int N);
		void SelectionSort(int arr[], int N);
		void MergeSort(std::vector<int>& arr, int start, int end);
		void InsertionSort(int arr[], int N);

	private:
		void Merge(std::vector<int>& arr, int start, int mid, int end);
	};
}

