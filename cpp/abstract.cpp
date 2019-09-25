#include <iostream>
using namespace std;

class B {
protected:
	int x;
	int y;

public:
	B() {
	}
	;

	void read() {
		cout << "x in class B?";
		cin >> x;
		cout << "y in class B?";
		cin >> y;
	}

	void show() {
		cout << "x in class B = " << x << endl;
		cout << "y in class B = " << y << endl;

	}

	void hello() {
		cout << "In hello()" << endl;
	}
};

class D: public B {
protected:
	int y;
	int z;

public:
	//B(){};

	void read() {
		B::read();
		cout << "y in class D?";
		cin >> y;
		cout << "z in class D?";
		cin >> z;
	}

	void show() {
		B::show();
		cout << "y in class D = " << y << endl;
		cout << "z in class D = " << z << endl;
		cout << "y of B, show from D=" << B::y << endl;
	}
};

int main() {
	D objd;
	cout << "Enter data for object of class D.." << endl;
	objd.read();
	cout << "contents of object of class D.." << endl;
	objd.show();
	objd.hello();
	return 0;
}
