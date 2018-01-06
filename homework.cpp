//Homework3
//Part 1
//Abdul Samad Khan
//5 functions are implemented in this class
//intialize array set odd place value to 0 and even to 1
//print_array prints the whole array
//selection sort arranging elements in descending order
//factorial runing recursively to find the result
#include"homework.h"
#include<iostream>

using namespace std;

void homework::initialize_array(int * arr, int size) {
	for (int i = 0; i < size; i++)
	{
		if (i % 2 == 0)
		{
			
			arr[i] = 1;
			
		}
		else
		{
			arr[i] = 0;

		}

	}

}
void homework::print_array(int * arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";


	}
	cout << endl;
}

void homework::selection_sort(int * arr, int size) {
	int minIndex;
	for (int index = 0; index < size - 1; index++) {
		minIndex = index;
		for (int scan = index + 1; scan < size; scan++) {
			if (arr[scan] > arr[minIndex]) {
				minIndex = scan;
			}
		}
		//swap the two elements, data[minIndex] and data[index]
		int temp = arr[minIndex];
		arr[minIndex] = arr[index];
		arr[index] = temp;
	}

}
int homework::factorial(int number) {

	if (number == 0)
	{
		return 1;
	}
	else
	{
		return number*factorial(number - 1);
	}
}


