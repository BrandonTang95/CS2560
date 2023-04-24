// 
// Name: Tang, Brandon
// Project: 5
// Due: 4/19/23
// Course: cs-2560-01-sp23 
// 
// Description: 
// Test file for the IntArray class.
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

#include "IntArray.h"

using namespace std;

int main ()
{
	cout << "IntArray by B. Tang" << endl;
	cout << endl;
	
	IntArray myArray(100);

	ifstream infile ("input.dat");
	int value;
	while (infile >> value)
	{
		myArray.add(value);
	}

	infile.close();

	cout << "Data count = " << myArray.getLength() << endl;										
	cout << "Values = " << myArray.toString() << endl;										

	int* parray = myArray.toArray();
	int sum = 0;
	for (int i = 0; i < myArray.getLength(); i++)
	{
		sum += *(parray + i);
	}
	
	cout << "Sum = " << sum << endl;										
	cout << setprecision(1) << fixed;
	cout << "Average = " << static_cast<double>(sum) / myArray.getLength() << endl;			

	// Testing set and get
	cout << "Change the first element to 5." << endl;
	myArray.set(0, 5);
	cout << "First element is " << myArray.get(0) << "." << endl;	
	cout << "Last element in the array is " << myArray.get(myArray.getLength() - 1) << "." << endl;

	cout << "Find the 300th element in the array." << endl;
	cout << myArray.get(300);
	
	return 0;
}

