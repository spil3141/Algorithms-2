#include "Sorter.h"

namespace Algorithm {

	template<typename T>
	inline void Swap(T& a, T& b)
	{
		T temp = a;
		a = b;
		b = temp;
	}

	void Sorter::BubbleSort(int arr[], int N)
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < (N - 1) - i; j++)
				if (arr[j] > arr[j + 1])
					Swap(arr[j], arr[j + 1]);
	}

	void Sorter::SelectionSort(int arr[], int N)
	{
		for (int i = 0; i < N; i++)
		{
			int* min = &arr[i];
			for (int j = i + 1; j < N; j++)
				if (arr[j] < *min)
					min = &arr[j];
			Swap(arr[i], *min);
		}
	}


	void Sorter::Merge(std::vector<int>& arr, int start, int mid, int end)
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

	void Sorter::MergeSort(std::vector<int>& arr, int start, int end)
	{
		if (start < end)
		{
			int mid = (start + end) / 2;
			MergeSort(arr, start, mid); // mergesort left half
			MergeSort(arr, mid + 1, end); // mergesort right half
			Merge(arr, start, mid, end);  // merge both halves
		}

	}
}