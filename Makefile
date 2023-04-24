
a.out : Circle.o CircleTest.o
	g++ CircleTest.o Circle.o

Circle.o : Circle.h Circle.cpp
	g++ -c Circle.cpp

CircleTest.o : Circle.h CircleTest.cpp
	g++ -c CircleTest.cpp	