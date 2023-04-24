
// cpp.cos.cs.2560.sp23 - Student

/*
	1. Construct a singly linked list of Students of data from a file
	2. Convert the singly linked list into an array
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Student.h"

using namespace std;

struct Node {
	Student* student;
	Node *next;
};

int main ()
{
	Node* head = nullptr;
	ifstream inFile("students.dat");
	Student s;
	int count = 0;

	if (!inFile) {
		cerr << "file open error" << endl;
		exit(EXIT_FAILURE);
	}

	while (inFile >> s.id >> s.name) {
		Node* node = new Node;
		node->student = new Student;
		*node->student = s;
		node->next = head;
		head = node;
		count++;
	}
	inFile.close();

#if 0
	Node* current = head;
	while (current != nullptr) {
		cout << current->student->id << " : " << current->student->name << endl;
		current = current->next;
	}
#endif

#if 0  // pointer to an array of Students
	Student* array = new Student[count];

	Node *current = head;
	int i = count - 1;
	while (current != nullptr) {
		*(array + i) = *current->student;
		i--;
		current = current->next;
	}
	
	for (int i = 0; i < count; i++) {
		cout << (array +i)->id << " : " << (array + i)->name << endl;
	}

	// delete linked list of Nodes and Students pointed by Nodes
#endif

#if 0  // pointer to an array of pointers to pointer to Student
	Student** array = new Student*[count];
	Node *current = head;
	int i = count - 1;
	while (current != nullptr) {
		*(array + i) = current->student;
		i--;
		current = current->next;
	}

	for (int i = 0; i < count; i++) {
		cout << (*(array + i))->id << " : " << (*(array + i))->name << endl;
	}

	// delete linked list of Nodes
#endif

	return 0;
}
