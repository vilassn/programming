#include <stdio.h>

enum en {
	ADD = 0, SUB, DIV = 0, MUL, MOD, a, b, c, d
};

int main() {

	printf("%d %d %d %d %d\n", ADD, SUB, DIV, MUL, d);
	printf("size of enum %lu\n", sizeof(enum en));

	return 0;
}
