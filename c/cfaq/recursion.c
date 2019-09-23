#include <stdio.h>

int i;

// stack size is 8MB in linux
void func() {
	int j;
	i++;
	printf("%d at %p, &j=%p\n", i, &i, &j);
	func();
}

int main() {

	func();

	// Treat 0 as an address, de-reference the 0 address and try and store 0 into it.
	// This should segfault, null pointer de-reference.

	//*(int *) 0 = 0;

	return 0;
}

