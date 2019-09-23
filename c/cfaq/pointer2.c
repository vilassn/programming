#include <stdio.h>

int main() {

	// const int
	int constint = 10;
	// constint = 1; // error: assignment of read-only variable ‘constint’

	// This is a pointer to a constant int.
	// You cannot change the value pointed by ptr, but you can change the pointer itself
	const int *ptr2const;
	ptr2const = &constint;
	// *ptr2const = 1; // error: assignment of read-only location ‘*ptr2const’

	// This is a constant pointer to non-constant int.
	// You cannot change the pointer p, but can change the value pointed by ptr.
	int val = 10;
	int * const constptr = &val;
	// constptr = 0x1000; // error: assignment of read-only variable ‘constptr’
	*constptr = 20;

	// This is a constant pointer to constant int.
	// You can neither change the value pointed by ptr nor the pointer ptr.
	int val1 = 10;
	const int * const constptr2constint = &val1;
	// constptr2constint = 0x1000; //error: assignment of read-only variable ‘constptr2constint’
	// *constptr2constint = 20; // error: assignment of read-only location ‘*constptr2constint’

	/*****************************/

	int *intptr = (int *) 0x1000;
	void *voidptr = intptr;

	intptr++;  //Increments by 4 bytes
	voidptr++; //Increments by 1 byte

	printf("intptr=%p, voidptr=%p\n", intptr, voidptr);

	return 0;
}
