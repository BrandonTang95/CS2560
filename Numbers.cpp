
#include <iostream>
#include <cstdlib>

#include "Numbers.h"

Numbers::Numbers(int size)
{
	this->size = size;
	array = new double[size];
}

Numbers::~Numbers ()
{
	delete[] array;
}

void Numbers::chkIndex (int index) const
{
	if (index < 0 || index >= size) {
		std::cerr << index << " out of bound" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void Numbers::set(int index, double value)
{
	chkIndex(index);
	*(array + index) = value;
}

double Numbers::get(int index) const
{
	chkIndex(index);
	return *(array + index);
}

double Numbers::getAverage() const
{
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += *(array + i);
	}

	return sum / size;
}