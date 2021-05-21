#include <iostream>
#include <vector>

#define MAX 100000

#include "Utils/Timer.h"
#include "Algorithms/Sorter.h"
#include "Utils/Random.h"

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



static void ResetArray(std::vector<int>& arr, int length)
{
	arr.clear();
	for (int i = 0; i < length; i++)
	{
		arr.push_back(Utils::Random::RandInt());
	}
}

int main()
{
	Algorithm::Sorter Sorter;
	Utils::Random::Init();

	std::cout << "Welcome to the world of algorithms." << std::endl;
	std::cout << "Sorting Algorithms: " << std::endl;

	std::vector<int> Arr1;// = { 8,4,5,1,7,2,6,3,0,9,4,12,32,11,23,8,4,5,1,7,2,6,3,0,9,4,12,32,11,23,8,4,5,1,7,2,6,3,0,9,4,12,32,11,23 };
	ResetArray(Arr1, MAX);


	// Before Sorting 
	//Display(Arr1, "Display Data before: ");

	{		
		std::cout << "Bubble Sort\n";
		Utils::Timer timer;
		Sorter.BubbleSort(&Arr1[0], Arr1.size());
	}
	ResetArray(Arr1, MAX);
	{
		std::cout << "Selection Sort\n";
		Utils::Timer timer;
		Sorter.SelectionSort(&Arr1[0], Arr1.size());
	}
	ResetArray(Arr1, MAX);
	{
		std::cout << "Insertion Sort\n";
		Utils::Timer timer;
		Sorter.InsertionSort(&Arr1[0], Arr1.size());
	}
	ResetArray(Arr1, MAX);
	{
		std::cout << "Merge Sort\n";
		Utils::Timer timer;
		Sorter.MergeSort(Arr1, 0, Arr1.size() - 1);
	}
	

	// After Sorting 
	//Display(Arr1, "After   :");


	std::cin.get();
}