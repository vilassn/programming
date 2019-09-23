#include <stdio.h>

/*
 * factorial of a positive integer n, denoted by n!,
 * it is the product of all positive integers less than or equal to n
 *
 * num factorial
 * 0 	1
 * 1 	1
 * 2 	2
 * 3 	6
 * 4 	24
 */

int factorial(int n) {

	if (n == 1)
		return 1;

	return (n * factorial(n - 1));
}

int main() {

	int num;
	printf("Enter value MAX:17\n");
	scanf("%d", &num);

	if (num == 0) {
		printf("factorial of zero is 1\n");
	} else {

		int fact = 1;
		for (int i = num; i >= 0; i--)
			fact = fact * i;

		printf("factorial by loop is %u\n", fact);
		printf("factorial by recursion is %u\n", factorial(num));
	}

	return 0;
}

