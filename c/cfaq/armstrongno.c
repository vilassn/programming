/*If sum of cube of all digits of a number is same as the number then it is called as armstrong number.

 Example: 153
 153=(1*1*1)+(5*5*5)+(3*3*3)
 */

#include <stdio.h>

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

int main() {
	int num1, num2;

	printf("Enter two numbers(intervals): ");
	scanf("%d %d", &num1, &num2);

	printf("Armstrong numbers between %d an %d are: ", num1, num2);

	for (int num = num1; num <= num2; num++) {
		if(armstrong(num))
		printf("%d ", num);
	}

	return 0;
}
