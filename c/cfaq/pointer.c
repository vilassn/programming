#include <stdio.h>

//How does free() know the size of memory to be deallocated?
//
//When memory allocation is done, the actual heap space allocated is one word larger than the requested memory.
//The extra word is used to store the size of the allocation and is later used by free( )
//
//When you call for memory to be allocated on the heap, a system call is made to the kernel space of the OS to provide this memory.
//This memory is mapped to your process structure, which is maintained by the OS. When your program exits,
//the OS goes through a clean up routing, closing all file descriptors, and marks this memory free for allocation to other processes (among other things).

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
