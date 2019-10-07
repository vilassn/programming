#include <stdio.h>

typedef struct temp {
	int data;
	struct temp*ptr;
} Temp;

int main() {

	while (1) {
		malloc(sizeof(Temp));
	}

	return 0;
}
