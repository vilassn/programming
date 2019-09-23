//http://www.codeproject.com/Articles/28663/Explicit-Constructor-in-C

#if 0
#include <iostream>
using std::cout;
using std::endl;
class complexNumbers {
	double real, img;
public:
	complexNumbers() : real(0), img(0) {}
	complexNumbers(const complexNumbers& c) {real = c.real; img = c.img;}
	complexNumbers( double r, double i = 0.0) {real = r; img = i;}
	friend void display(complexNumbers cx);
};
void display(complexNumbers cx) {
	cout<<"Real Part: "<<cx.real<<" Imag Part: "<<cx.img<<endl;
}
int main() {
	complexNumbers one(1);
	complexNumbers five = 5;
	display(one);
	display(five);
	return 0;
}
#endif

#if 0
#include <iostream>
using std::cout;
using std::endl;
class complexNumbers {
	double real, img;
public:
	complexNumbers() : real(0), img(0) {}
	complexNumbers(const complexNumbers& c) {real = c.real; img = c.img;}
	complexNumbers( double r, double i = 0.0) {real = r; img = i;}
	friend void display(complexNumbers cx);
};
void display(complexNumbers cx) {
	cout<<"Real Part: "<<cx.real<<" Imag Part: "<<cx.img<<endl;
}
int main() {
	complexNumbers one(1);
	display(one);
	display(300);
	return 0;
}
#endif

#if 1
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
#endif

