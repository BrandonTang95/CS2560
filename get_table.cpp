// 
//  Name:   Tang, Brandon 
//  Project:  4
//  Due:        3/15/23 
//  Course:  cs-2560-01-sp23 
// 
//  Description: 
//    A program with the fuction get_table that will return a pointer to array of pointers to the 
//    elements and the number of elements read from the file periodictable.dat via call by reference parameter.
// 

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Element.h"

using namespace std;

struct Node
{
	Element* element;
	Node* next;
};

Element* get_table(int &count)
{
       Node* head = nullptr;
	ifstream inFile("periodictable.dat");
       Element e;
       count = 0;

	// Error opening file
       if (!inFile) 
       {
		cerr << "File open error." << endl;
		return nullptr;
	}

	// Read in fields of file
	while (inFile >> e.atomicNum >> e.abr >> e.mass >> e.name)
	{
		// Create new Node pointer
		Node* nodep = new Node;

		// Node pointer pointing to new element
		nodep->element = new Element;
		*nodep->element = e;
		nodep->next = head;
		head = nodep;
		count++;
	}

	inFile.close();

	// Pointer to an array of Elements
	Element* elements = new Element[count];

	Node* current = head;
	int i = count - 1;
	while (current != nullptr) 
	{
		*(elements + i) = *current->element;
		i--;

		// Delete linked list of Nodes and elements pointed by Nodes
		delete current->element;

		// Create temp variable to access next Node after deallocation
		Node* temp = current->next;
		delete current;
		current = temp;
	}

	return elements;
}
