// 
//  Name:   Tang, Brandon 
//  Project:  4
//  Due:        3/15/23 
//  Course:  cs-2560-01-sp23 
// 
//  Description: 
//    A main program that will read in the periodic table, sort the periodic table using the element names and call
//    print_table to output the sorted periodic table.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include "Element.h"

using namespace std;

// Prototypes
void selectionSort(Element* elements, int size);
void swap(Element &x, Element &y);

// Main to test functions
int main()
{      
       int size = 0;
       
       Element* elements = get_table(size);

       selectionSort(elements, size);

       print_table(elements, size);

       return 0;
}

// Sort elements in alphabetical order
void selectionSort(Element* elements, int size)
{
       int minIndex;
       for (int start = 0; start < (size - 1); start++)
       {
              minIndex = start;
              Element minValue = elements[start];
              for (int index = start + 1; index < size; index++)
              {
                     int i = 0;

                     // Loop until a character is different
                     while (elements[index].name[i] == elements[start].name[i])
                     {
                            i++;
                     }

                     // Compare characters and change minIndex if true
                     if (elements[index].name < elements[minIndex].name)
                     {
                            minIndex = index;
                     }
              }

              // Swap starting element and minimum index in unsorted partition
              swap(elements[start], elements[minIndex]);
       }
}

// Swap elements in the sorting function
void swap(Element &x, Element &y)
{
	Element temp;
	temp = x;
	x = y;
	y = temp;
}
