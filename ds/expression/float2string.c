#include<stdio.h>
main() {
	int mantissa, exponant, ndigs = 0, temp;
	float result;
	char str[20];
	printf("Enter the value of result: ");
	scanf("%f", &result);
	mantissa = (int) result;
	result = result - mantissa;
	exponant = (int) (result * 10000);
	printf("\nmantissa =%d   exponent=%d", mantissa, exponant);

	/* count no. of digits in mantissa */
	temp = mantissa;
	while (temp != 0) {
		ndigs++;
		temp /= 10;
	}

	ndigs += 5;
	str[ndigs] = '\0';

	while (exponant != 0) {
		str[--ndigs] = (exponant % 10) + 48;
		exponant = exponant / 10;
	}

	str[--ndigs] = '.';

	while (--ndigs != -1) {
		str[ndigs] = (mantissa % 10) + 48;
		mantissa = mantissa / 10;
	}

	printf("\nResult in string is = %s", str);
}
