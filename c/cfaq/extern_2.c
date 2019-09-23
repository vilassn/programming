#include <stdio.h>

extern i; // warning: type defaults to ‘int’ in declaration of ‘i’
int j; // it is also extern as it is global in extern_1.c

int print() {

	printf("In %s, i=%d, j=%d\n", __func__, i, j);
	j++;
	i++;

	return 0;
}
