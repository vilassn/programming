#include <stdio.h>

main() {

	printf("A-Z=%d-%d,a-z=%d-%d\n", 'A', 'Z', 'a', 'z');

	printf("\\r:%d\n", '\r');
	printf("\\0:%d\n", '\0');
	printf("\\a:%d\n", '\a');
	printf("\\n:%d\n", '\n');

	printf("NULL:%d\n", NULL); //=>0
	printf("EOF:%d\n", EOF); //=>-1

	printf("\\n:%d\n", '\b'); //backspace
}
