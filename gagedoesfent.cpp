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

double* Get_Input();
void Sort_Array(double* arrPtr[], const int SIZE);
double Calc_Average(double* arrPtr[], const int SIZE);
void Write_Array(double* arrPtr[], const int SIZE);
double swap(double*&, double*&);

int main()
{
	return 0;
}

double* Get_Input()
{
	int size = 0;

	cout << "How many grades would you like to input? : ";
	cin >> size;

	double* Array_Ptr = new double[size];
}

void Sort_Array(double* arrPtr[], const int SIZE)
{

}

double Calc_Average(double* arrPtr[], const int SIZE)
{
	return 0.0;
}

void Write_Array(double* arrPtr[], const int SIZE)
{

}

double swap(double*& a, double*& b)
{
	return 0.0;
}
