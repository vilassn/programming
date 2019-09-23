#include<stdio.h>
main() {
	int result, temp, flag = 0;
	char str[20];

	printf("Enter the value of result: ");
	scanf("%d", &result);
	temp = result;

	/* count no. of digits in result in flag */
	while (temp != 0) {
		flag++;
		temp = temp / 10;
	}

	/* store digits in string */
	str[flag] = '\0';
	while (--flag != -1) {
		str[flag] = (result % 10) + 48;
		result = result / 10;
	}

	printf("\nResult in string is = %s", str);
}
