//http://www.codeproject.com/Articles/28663/Explicit-Constructor-in-C

#include <iostream>
using std::cout;
using std::endl;

// Now if you try
//
// String mystring = 'x';
//
// the char 'x' will be converted to int and will call String(int) constructor.
// But this is not what the user might have intended.
//
// So to prevent such conditions, we can define the class's constructor as explicit.

class String {

public:
	explicit String(int n); //allocate n bytes
	String(const char *p); // initialize sobject with string p
}

int main() {

	Foo mystring = 'x';

	return 0;
}

