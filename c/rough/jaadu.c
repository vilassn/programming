#include<stdio.h>
main() {
	int i = 0;
	printf("\n\n\n\n\n\n...............");
	while (1) {
		for (i = 0; i < 99999; i++)
			printf("\b%c", '-');

		for (i = 0; i < 99999; i++)
			printf("\b%c", '\\');

		for (i = 0; i < 99999; i++)
			printf("\b%c", '|');

		for (i = 0; i < 99999; i++)
			printf("\b%c", '/');
	}
}
