// Implementation file for the IntegerList class.

#include <iostream>
#include <cstdlib>

#include "IntegerList.h"

using namespace std;

//***********************************************************
// The constructor sets each element to zero.               *
//***********************************************************

IntegerList::IntegerList (int size)
{
	list = new int[size];
	numElements = size;
	for (int i = 0; i < size; i++) {
		*(list + i) = 0;
	}
}

int IntegerList::getLength () const
{
	return numElements;
}

//***********************************************************
// The destructor releases allocated memory.                *
//***********************************************************

IntegerList::~IntegerList()
{
	delete[] list;
}

//***********************************************************
// isValid member function.                                 *
// This private member functon returns true if the argument *
// is a valid subscript, or false otherwise.                *
//***********************************************************

bool IntegerList::isValid (int element) const
{
	return element >= 0 || element < numElements;
}

//***********************************************************
// setElement member function.                              *
// Stores a value in a specific element of the list. If an  *
// invalid subscript is passed, the program aborts.         *
//***********************************************************

void IntegerList::setElement (int element, int value)
{
	if (isValid(element)) {
		*(list + element) = value;
	} else {
		std::cerr << "Error: Invalid subscript - " << element << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

//***********************************************************
// getElement member function.                              *
// Returns the value stored at the specified element.       *
// If an invalid subscript is passed, the program aborts.   *
//***********************************************************

int IntegerList::getElement (int element) const
{
	if (isValid(element)) {
		return *(list + element);
	} else {
		std::cerr << "Error: Invalid subscript - " << element << std::endl;
		std::exit(EXIT_FAILURE);
	}
}