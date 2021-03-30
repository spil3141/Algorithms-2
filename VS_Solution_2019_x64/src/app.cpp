#include <iostream>
#include <vector>
#include "Sort/Sort.h"
#include "Utils/Timer.h"

template<typename T>
static void Display(std::vector<T>& arr, std::string label)
{
	std::cout << std::endl;
	std::cout << label.c_str();
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << std::endl;
}

int main()
{
	std::cout << "Welcome to the world of algorithms." << std::endl;
	std::cout << "Sorting Algorithms: " << std::endl;
	
	std::vector<int> Arr1 = { 8,4,5,1,7,2,6,3,0,9,4,12,32,11,23,8,4,5,1,7,2,6,3,0,9,4,12,32,11,23,8,4,5,1,7,2,6,3,0,9,4,12,32,11,23, };


	// Before Sorting 
	Display(Arr1, "Display Data before: ");

	// Sort Algorithms
	//SP::Algorithm::BubbleSort<int>(Arr1);
	SP::Algorithm::BubbleSort(&Arr1[0], Arr1.size());
	Arr1 = { 8,4,5,1,7,2,6,3,0,9 };
	SP::Algorithm::SelectionSort(&Arr1[0], Arr1.size());
	Arr1 = { 8,4,5,1,7,2,6,3,0,9 };
	SP::Algorithm::InsertionSort(&Arr1[0], Arr1.size());
	Arr1 = { 8,4,5,1,7,2,6,3,0,9 };
	{
		std::cout << "Merge Sort:" << std::endl;
		SP::Utility::Timer timer;
		SP::Algorithm::MergeSort(Arr1,0, Arr1.size()-1);
	}


	// After Sorting 
	Display(Arr1, "After   :");


	std::cin.get();
}