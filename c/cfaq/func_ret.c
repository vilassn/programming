#include<stdio.h>

int i = 4;

print() {
	return i--;
}

main() {

	print();
	printf("%d", i);        //i=3
}
