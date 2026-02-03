#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <fstream>
#include <memory>
#include <array>
#include <sstream>
#include <cstdlib>
using namespace std;

double* Get_Input(int SIZE);
void Sort_Array(double arrPtr[], const int SIZE);
double Calc_Average(double* Array_Pointer, const int SIZE);
void Write_Array(double* arrPtr, const int SIZE);
double swap(double*&, double*&);

int main()
{ 
	// Init
	int Size = 0;
	double Average = 0;

	// Taking input
	while (Size <= 0)
	{
		cout << "How many grades would you like to input? : ";
		cin >> Size;
	}
	// Making the array pointer
	double *Array_Pointer = Get_Input(Size);

	// Sort the array
	Sort_Array(Array_Pointer, Size);

	// Calculate and display the average
	Average = Calc_Average(Array_Pointer, Size);

	cout << "The average of the input grades, without the lowest, is " << Average << endl;

	// Store the array to a file.
	Write_Array(Array_Pointer, Size);

}

double* Get_Input(int SIZE)
{
	// Init
	double* Array_Ptr = new double[SIZE];

	// Take input
	for (int Count = 0; Count < SIZE; Count++)
	{
		double Grade;
		cout << "Input grade: ";
		cin >> Grade;
		Array_Ptr[Count] = Grade;
	}

	// Return
	return Array_Ptr;
}

void Sort_Array(double arrPtr[], const int SIZE)
{
	for (int start = 0; start < SIZE - 1; ++start)
	{
		int minIndex = start;
		double minValue = arrPtr[start];

		for (int index = start + 1; index < SIZE; ++index)
		{
			if (arrPtr[index] < minValue)
			{
				minValue = arrPtr[index];
				minIndex = index;
			}
		}
		swap(arrPtr[minIndex], arrPtr[start]);
	}
}

double Calc_Average(double* Array_Pointer, const int SIZE)
{
	// Find minimum
	double Minimum = Array_Pointer[0];

	// If the array is = 1, then return the minimum as the average.
	if (SIZE == 1)
	{
		return Minimum;
	}

	// Iniitalized total
	double Total = 0;

	// Add up the total
	for (int Count = 0; Count < SIZE; Count++)
	{
		Total += Array_Pointer[Count];
	}

	// Find the average after subtracting the minimum.
	Total -= Minimum;
	return Total / (SIZE - 1);
}

void Write_Array(double* arrPtr, const int SIZE)
{
	ofstream inFile;
	inFile.open("results.txt");

	for (int Count = 0; Count < SIZE; Count++)
	{
		inFile << arrPtr[Count] << endl;
	}
	
}

double swap(double*& a, double*& b)
{
	double* temp = a;
	a = b;
	b = temp;

	return 0;
}
