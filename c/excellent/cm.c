#include<stdio.h>
main() {

	int num, bitpos;

	printf("enter num: ");
	scanf("%d", &num);

	printf("\nbefor complementing\n");

	for (bitpos = 31; bitpos >= 0; bitpos--)
		(num & (1 << bitpos)) ? printf("1") : printf("0");

	printf("\nAfter complementing\n");

	for (bitpos = 31; bitpos >= 0; bitpos--)
		!(num & (1 << bitpos)) ? printf("1") : printf("0");

	printf("\n");
}
