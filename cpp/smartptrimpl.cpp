#include<iostream>
using namespace std;

class SmartPtr {
	int *ptr;  // Actual pointer
public:
	// Constructor: Refer https://www.geeksforgeeks.org/g-fact-93/
	// for use of explicit keyword
	explicit SmartPtr(int *p = NULL) {
		ptr = p;
	}

	// Destructor
	~SmartPtr() {
		cout << "Destroyed" << endl;
		delete (ptr);
	}

	// Overloading dereferencing operator
	int &operator *() {
		return *ptr;
	}
};

void testSmrtPtr() {

	SmartPtr ptr(new int());
	*ptr = 20;
	cout << *ptr << endl;

	// We don't need to call delete ptr: when the object
	// ptr goes out of scope, destructor for it is automatically
	// called and destructor does delete ptr.
}

int main() {

	testSmrtPtr();

	while (1)
		;

	return 0;
}
