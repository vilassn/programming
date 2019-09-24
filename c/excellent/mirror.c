#include<stdio.h>

main() {

	int i, j, num, count;
	printf("Enter the height: ");
	scanf("%d", &num);

	count = 2 * num - 3;
	for (i = 1; i <= num; i++) {
		for (j = 0; j < i; j++)
			printf("* ");
		for (j = 0; j < count; j++)
			printf("  ");
		for (j = 0; j < i; j++)
			printf("* ");
		printf("\n");
		count = count - 2;
	}
}

