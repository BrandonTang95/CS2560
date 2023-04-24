// 
// Name: Tang, Brandon
// Homework: 2
// Due: 3/22/23
// Course: cs-2560-01-sp23 
// 
// Description: 
//     The program will prompt the user for the size of an array. 
//     The function will allocate the dynamic array and load darray with random values from 1 to 100.
//     The values of darray will be outputted 8 values per line. Any dynamic memory left over will be deallocated.

#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>

using namespace std;

int* allocateDynamicArray(int size);

int main()
{
       const int VALUE_PER_LINE = 8;
       int size, perLine = 0;

       cout << "Dynamic Array by B. Tang" << endl;
       cout << endl;

       cout << "Enter size? ";
       cin >> size;
       cout << endl;
       
       int* numbers = allocateDynamicArray(size); 

       // printing out values of dynamic array
       for (int i = 0; i < size; i++)
       {
              cout << setw(3) << *(numbers + i);
              if (++perLine == VALUE_PER_LINE)                  
              {
                     perLine = 0;
                     cout << endl;
              }
              else
              {
                     cout << " ";
              }
       }

       if (perLine != 0)
       {
              cout << endl;
       }

       // deallocate dynamic memory
       delete [] numbers;
       numbers = 0;

       return 0;
}

int* allocateDynamicArray(int size)
{
       int* darray = new int[size];

       // constantly generating random integers
       srand(time(0));
       
       // load integers into array
       for (int i = 0; i < size; i++)
       {
              // random integers from 1 to 100
              int random = rand() % 100 + 1;

              // allocate memory
              *(darray + i) = random;
       }

       return darray;
}
