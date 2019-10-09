#include <stdio.h>
#include <stdlib.h>

int foo(void) {

	printf("Hello, I'm a shared library\n");

	int var = 1;
	int *ptr = (int*) malloc(sizeof(int));
	*ptr = ++var;
	var = ++*ptr;

	//free(ptr);
	return var;
}

