#include <stdio.h>  /* for printf */
#include <string.h> /* for strchr */

float inch_to_cm(int inch) {
	return inch * 2.54;
}

int main(void) {

	float (*func1)(int) = inch_to_cm;

	int inch;
	printf("Enter inch value: ");
	scanf("%d", &inch);

	printf("cm is %f\n", func1(inch));

	return 0;
}

