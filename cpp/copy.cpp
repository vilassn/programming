#include <stdio.h>

//How does C++ object looks like in Memory.
//
//Static class members are treated almost exactly like global variables / functions.
//Because they are not tied to an instance, there is nothing to discuss regarding memory layout.
//
//Class member variables are duplicated for each instance as you can imagine, as each instance can have its own unique values for every member variable.
//Class member functions only exist once in a code segment in memory. At a low level, they are just like normal global functions but they receive a pointer to this.
//
//When talking about virtual functions, polymorphism, then the memory layout gets more complicated, introducing a "vtable" which is basically a bunch of function pointers that define the topography of the class instance.
//
//A shallow copy of an object copies all of the member field values. This works well if the fields are values, but may not be what you want for fields that point to dynamically allocated memory. The pointer will be copied. but the memory it points to will not be copied -- the field in both the original object and the copy will then point to the same dynamically allocated memory, which is not usually what you want. The default copy constructor and assignment operator make shallow copies.
//

// A deep copy copies all fields, and makes copies of dynamically allocated memory pointed to by the fields.
// To make a deep copy, you must write a copy constructor and overload the assignment operator, otherwise the copy will point to the original, with disasterous consequences.
// The default copy constructor (which is automatically provided if you don't provide one yourself) creates only shallow copies.

//Shallow copy: Some members of the copy may reference the same objects as the original:

class X {
private:
	int i;
	int *pi;
public:

	X() :
			pi(new int) {
	}

	//Here, the pi member of the original and copied X object will both point to the same int.
	X(const X& copy)   // <-- copy ctor
	:
			i(copy.i), pi(copy.pi) {
	}
};

//Deep copy: All members of the original are cloned. There are no shared objects:

class X {
private:
	int i;
	int *pi;
public:

	X() :
			pi(new int) {
	}

	//Here, the pi member of the original and copied X object will point to different int objects, but both of these have the same value.
	X(const X& copy)   // <-- copy ctor
	:
			i(copy.i), pi(new int(*copy.pi)) // <-- note this line in particular!
	{
	}
};

