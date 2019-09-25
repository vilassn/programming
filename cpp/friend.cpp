#include <iostream>
using namespace std;

class A {
private:
	int value;

public:
	void setval(int v) {
		value = v;
	}

	int getval() {
		return value;
	}

	friend class B; //B is my friend. I trust him //Now, B can access private value of A but not viceversa.
	friend void decrement(A &what); // decrement() is also a good friend.
};

void decrement(A &a) {
	a.value--;
}

class B {
public:
	void touch(A &a) {
		a.value++;
	}
};

int main() {
	A obj;
	B obj2;

	obj.setval(5);
	decrement(obj);
	cout << "value= " << obj.getval() << endl;

	obj2.touch(obj);
	cout << "value= " << obj.getval() << endl;
}
