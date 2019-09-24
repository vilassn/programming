#include<stdio.h>

int main() {

	int x, y, pow = 1;
	printf("Enter x and y for (x^y): ");
	scanf("%d %d", &x, &y);

	if (y == 0) {
		pow = 1;
	} else {
		int tmp = y;
		while (tmp--) {
			pow = pow * x;
		}
	}

	printf("%d^%d = %d", x, y, pow);

	return 0;
}
