// 
//  Name:   Tang, Brandon 
//  Project:  4
//  Due:        3/15/23 
//  Course:  cs-2560-01-sp23 
// 
//  Description: 
//    Header file that defines the Element structure.
// 

#pragma once
#include <string>

using namespace std;

struct Element
{
       string name;         // Element name
       string abr;          // Element abbreviation
       int atomicNum;       // Element atomic number
       double mass;         // Element mass
};

Element* get_table(int &count);    // get table function
void print_table(Element* elements, int count);  // print table function
