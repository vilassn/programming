#include <iostream>
#include <stdio.h>
using namespace std;

/*
 Why does calling method through null pointer “work” in C++?
 The pointer isn't needed to call the method.
 The type of the pointer is known, so the code for the method is known.
 The method doesn't use this, so it runs the code just fine.
 It's undefined behavior, but its more efficient not to check if the pointer is NULL, so it runs.
 */

class A {
private:
	int x;
public:
	void func() {
		printf("A %p\n", this);
	}
};

class B: public A {
public:
	void func() {
		printf("B\n");
	}
};

int main() {
	A *obj;
	B *lmn;

	lmn->func();

	lmn = (B*) obj;
	lmn->func();

	printf("%p %p\n", lmn, lmn);
	obj = NULL;
	obj->func();
}

