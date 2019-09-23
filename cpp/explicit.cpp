//http://www.codeproject.com/Articles/28663/Explicit-Constructor-in-C

#include <iostream>
using std::cout;
using std::endl;

class complexNumbers {

	double real, img;

public:

	complexNumbers() :
			real(0), img(0) {
	}

	complexNumbers(const complexNumbers& c) {
		real = c.real;
		img = c.img;
	}

	explicit complexNumbers(double r, double i = 0.0) {
		real = r;
		img = i;
	}

	friend void display(complexNumbers cx);
};

void display(complexNumbers cx) {
	cout << "Real Part: " << cx.real << " Imag Part: " << cx.img << endl;
}

int main() {

	complexNumbers one(1);
	display(one);
	complexNumbers two = 2;
	display(200);

	return 0;
}

