#include <stdio.h>

// Armstrong no.: 0, 1, 153, 370, 371 and 407
// 153=(1*1*1) + (5*5*5)+(3*3*3)
int armstrong(int num) {

	int sum = 0;
	int temp = num;
	while (temp != 0) {
		int rem = temp % 10;
		sum = sum + rem * rem * rem;
		temp = temp / 10;
	}

	if (sum == num)
		return 1;

	return 0;
}

// Prime no.: 2, 3, 5, 7, 11, 13, 17, 19, 23 and 29.
// divided 1 and itself
int prime(int num) {

	int count = 0;
	for (int idx = 1; idx <= num; idx++) {
		if (num % idx == 0)
			count++;
	}

	if (count == 2)
		return 1;

	return 0;
}

int main() {

	int num1, num2;

	printf("Enter two numbers(intervals): ");
	scanf("%d %d", &num1, &num2);

	printf("Armstrong numbers between %d an %d are: ", num1, num2);
	for (int num = num1; num <= num2; num++) {
		if (armstrong(num))
			printf("%d ", num);
	}

	printf("\nPrime numbers between %d an %d are: ", num1, num2);
	for (int num = num1; num <= num2; num++) {
		if (prime(num))
			printf("%d ", num);
	}

	return 0;
}
