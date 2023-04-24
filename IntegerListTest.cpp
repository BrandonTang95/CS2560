
#include <iostream>

#include "IntegerList.h"

int main ()
{
	IntegerList il(10);

	std::cout << "set" << std::endl;
	for (int i = 0; i < il.getLength(); i++) {
		il.setElement(i, i * 2);
	}

	std::cout << "get" << std::endl;
	for (int i = 0; i < il.getLength(); i++) {
		std::cout << il.getElement(i) << std::endl;
	}
	il.getElement(120);

	return 0;
}