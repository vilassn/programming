//============================================================================
// Name        : CppPrograms.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Shape {
protected:
	int width, height;

public:
	Shape(int a = 0, int b = 0) {
		width = a;
		height = b;
	}

	virtual int area() {
		cout << "Parent class area :" << endl;
		return 0;
	}

	virtual ~Shape() {
		cout << "Parent class destructor :" << endl;
	}
};
class Rectangle: public Shape {
public:
	Rectangle(int a = 0, int b = 0) :
			Shape(a, b) {
	}

	~Rectangle() {
		cout << "Rectangle class destructor :" << endl;
	}

	int area() {
		cout << "Rectangle class area :" << endl;
		return (width * height);
	}
};

class Triangle: public Shape {
public:
	Triangle(int a = 0, int b = 0) :
			Shape(a, b) {
	}

	~Triangle() {
		cout << "Triangle class destructor :" << endl;
	}

	int area() {
		cout << "Triangle class area :" << endl;
		return (width * height / 2);
	}
};

// Main function for the program
int main() {
	Shape *shape;
	Rectangle rec(10, 7);
	Triangle tri(10, 5);

	// store the address of Rectangle
	shape = new Rectangle(10, 7);

	// call rectangle area.
	shape->area();

	// store the address of Triangle
	shape = new Triangle(10, 5);

	// call triangle area.
	shape->area();

	delete shape;

	cout << "Before while 1 :" << endl;
	while (1)
		;
	cout << "After while 1 :" << endl;

	return 0;
}
