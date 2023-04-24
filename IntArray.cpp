// 
// Name: Tang, Brandon
// Project: 5
// Due: 4/19/23
// Course: cs-2560-01-sp23 
// 
// Description: 
// Implementation file for the IntArray class.
//
#include <iostream>
#include <cstdlib>

#include "IntArray.h"

using namespace std;

// Constructor
IntArray::IntArray (int size)
{
       this->size = size;
       darray = new int[size];
       numElements = 0;
}


// Destructor
IntArray::~IntArray()
{
       delete [] darray;
}


// getLength 
int IntArray::getLength() const
{
       return numElements;
}


// get
int IntArray::get (int element) const
{
       if (element >= 0 && element < numElements) 
       {
              return *(darray + element);
       } 
       else 
       {
              cerr << "IntArray: index " << element << " out of bound" << endl;
              exit(1);
       }
}


// set
void IntArray::set (int element, int value)
{
       if (element >= 0 && element < numElements) 
       {
              *(darray + element) = value;
       } 
       else 
       {
              cerr << "IntArray: index " << element << " out of bound" << endl;
              exit(1);
       }
}


// add
bool IntArray::add(int value)
{
       if(numElements == size)
       {
              size_t new_size = size * 2;
              int* new_darray = new int[new_size];

              memcpy(new_darray, darray, size * sizeof(int));
              size = new_size;
              delete [] darray;
              darray = new_darray;

              *(darray + numElements) = value;
              numElements++;
       }

       *(darray + numElements) = value;
       numElements++;
       
       return true;
}


// toArray
int* IntArray::toArray()
{
       int *temp = new int[numElements];
       memcpy(temp, darray, numElements * sizeof(int));
       return temp;
}


// toString
std::string IntArray::toString()
{
       string output = "";
       for (int i = 0; i < numElements; i++)
       {
              output += to_string(*(darray + i));
              if(i != numElements - 1)
              {
                     output += ",";
              }
       }

       return output;
}
