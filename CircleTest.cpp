
#include <iostream>

#include "Circle.h"

using namespace std;

void	display (const Circle &c)
{
	cout << "Circle(" << c.getRadius() << ")" << endl;
}

int main ()
{
	Circle c;

	display(c);
	cout << "\t\t" << c.getDiameter() << endl;

	c.setRadius(10);
	display(c);
	cout << "\t" << c.getDiameter() << endl;
}