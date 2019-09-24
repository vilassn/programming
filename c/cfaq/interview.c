#include<stdio.h>

main() {

	int i = 5, k = 10;

	i = (i || k) = 7; // i.e. i=(i || k)=7; //error: lvalue required as left operand of assignment

	printf("%d\n", i);
}
