#include <stdio.h>

int c = -1;

main() {

	f(3);
	printf("%d\n", c);
}

f(int t) {
	switch (t) {
	default:
		c = 0;
	case 2:
		c = 3;
	case 3:
		c = 4;
	case 4:
		c = 5;
	case 5:
		c = 6;
	}
}
