#include<stdio.h>
#include<malloc.h>


void test(int size)
{

	int *p;
	int i = 0;
	p = malloc(size);
	getchar();
	printf("\n %p \n", p);
	free(p);
}

int main()
{
	test(128);
	return 0;
}
