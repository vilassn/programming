#include<stdio.h>

int i = 4;

int print() {
	return i--;
}

int main() {

	printf("%d\n", i);				//i=4
	printf("%d\n", print());		//i=4
	printf("%d\n", i);				//i=3

	return 0;
}
