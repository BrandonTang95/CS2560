
#include <iostream>
#include <cstdlib>

#include "Numbers.h"

using namespace std;


int main ()
{
	Numbers myTemps(50);

	for (int i = 0; i < 50; i++) {
		myTemps.set(i, rand() % ((130 - 10) + 1) + 10);
	}

	cout << myTemps.get(0) << endl;
	cout << myTemps.get(49) << endl;
	cout << myTemps.getAverage() << endl;

	return 0;
}