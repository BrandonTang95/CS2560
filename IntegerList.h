// Specification file for the the IntegerList class.

#pragma once

class IntegerList
{
private:
	int *list;			// Pointer to the array.
	int numElements;		// Number of elements.
	bool isValid(int) const; // Validates subscripts.
public:
	IntegerList(int size);				 // Constructor
	~IntegerList();					 // Destructor
	int getLength() const;
	void setElement(int element, int value); // Sets an element to a value
	int getElement(int elementnt) const;	 // Returns an element
};
