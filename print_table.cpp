// 
//  Name:   Tang, Brandon 
//  Project:  4
//  Due:        3/15/23 
//  Course:  cs-2560-01-sp23 
// 
//  Description: 
//     A program that will print the periodic table.
// 

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include "Element.h"

using namespace std;

void print_table(Element* elements, int count)
{ 
       double sum = 0;

       cout << "Periodic Table by B. Tang" << endl;
       cout << endl;

       cout << "Name                    Abr ANo   Mass" << endl;
       cout << "----------------------- --- --- ------" << endl;

       cout << fixed << showpoint;
       for(int i = 0; i < count; i++)
       {
              sum += elements[i].mass;

              cout << left;
              cout << setw(24) << elements[i].name;

              cout << right;
              cout << setw(3) << elements[i].abr; 
              cout << setw(4) << elements[i].atomicNum; 
              cout << setw(7) << setprecision(2) << elements[i].mass << endl;
       }

       cout << endl;
       cout << "The average mass = " << right << setw(19) << setprecision(2) << sum / count << endl;
       cout << "The number of elements =    " << count << endl;
}
