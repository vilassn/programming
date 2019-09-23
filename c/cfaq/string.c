#include <stdio.h>

int main() {

	char str[10] = "vector"; //data section - rw memory
	char *ptr = "institute"; //code section read only memory

	strcpy(str, ptr);
	printf("str=%s\n", str);

	// strcpy(ptr, str); //segfault
	printf("ptr=%s\n", ptr);

	// ptr[0]-=32; //seg fault
	printf("ptr=%s\n", ptr);

	ptr = str;
	ptr[0] -= 32;
	str[1] -= 32;
	printf("%s\n", str);
}
