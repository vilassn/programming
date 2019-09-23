#include <stdio.h>

f1(int x, int y) //x=1, y=2
{
	printf("%d, %d\n", x, y);
}

void main() {

	int x = 1;
	int y = 2;

	f1(x++, y++);

	int i = 1;
	printf("%d\n", ++i + ++i); //6

	i = 1;
	printf("%d\n", i++ + ++i); //4

	i = 1;
	printf("%d\n", i++ + i++); //2

	i = 1;
	printf("%d\n", ++i + i++); //4
}

