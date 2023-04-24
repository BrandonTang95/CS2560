// 
// Name: Tang, Brandon
// Project: 5
// Due: 4/19/23
// Course: cs-2560-01-sp23 
// 
// Description: 
// Declaration file for the IntArray class.
//
#pragma once

class IntArray
{
       private:
              int *darray;
              int size;
              int numElements;
       public:
              IntArray(int size = 100);
              ~IntArray();
              int getLength() const;
              int get(int element) const;
              void set(int element, int value);
              bool add (int value);
              int* toArray();
              std::string toString();
};
