#include<stdio.h>
#include<string.h>

main() {

	int i, n1, temp, num, div[] = { 1000000000, 10000000, 100000, 1000, 100 };

	char *name[10] = { "Billion", "Crore", "Lac", "Thousand", "Hundred", "" };

	char a[100][10] = { "", "One", "Two", "Three", "Four", "Five", "Six",
			"Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen",
			"Forteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
			"Nineteen", "Twenty" };

	strcpy(a[30], "Thirty");
	strcpy(a[40], "Forty");
	strcpy(a[50], "Fifty");
	strcpy(a[60], "Sixty");
	strcpy(a[70], "Seventy");
	strcpy(a[80], "Eighty");
	strcpy(a[90], "Ninety");

	printf("Enter the number: ");
	scanf("%d", &num);

	temp = num;
	for (i = 0; i <= 5; i++) {

		if (i != 5)
			n1 = num / div[i];
		else {
			n1 = num;
			if (n1 != 0 && temp > 100)
				printf(" and");
		}

		if (n1 > 20 && n1 < 100)
			printf(" %s %s %s", a[(n1 / 10) * 10], a[n1 % 10], name[i]);
		else if (n1)
			printf(" %s %s", a[n1], name[i]);
		num = num - n1 * div[i];
	}

	if (temp == 0)
		printf("Zero");
	printf("\n\n");
}
