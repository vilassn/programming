#include <stdio.h>

//static int i; //limiting scope only to this file, give error: extern_2.c: undefined reference to `i'
int i;
int j;

int main() {

	i = 10;
	j = 20;
	print();
	printf("In %s, i=%d, j=%d\n", __func__, i, j);

	return 0;
}
