
#include "Circle.h"

Circle::Circle ()
{
	radius = 1;
}

void Circle::setRadius (double radius)
{
	this->radius = radius;
}

double Circle::getRadius () const
{
	return radius;
}

double Circle::getDiameter () const
{
	return radius * 2;
}
