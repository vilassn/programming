#include <stdio.h>

int main() {

	int year = 0;
	static int i = 0;

	while (year < 2020) {

		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
			printf("%4d leap year\n", year);
			i++;
		}
		year++;
	}

	printf("%d total leap years %d\n", i);
	return 0;
}
