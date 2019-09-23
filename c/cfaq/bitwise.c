#include <stdio.h>

int main() {

	unsigned int i;

	i = 0x01 << 31;
	printf("%d\n", i); //-2147483648

	printf("%u\n", i); //2147483648

	printf("%u\n", -1); //4294967295

	printf("%d\n", -1); //-1

	i = 1 << 32;
	printf("%d\n", i); //0 // warning: left shift count >= width of type

	i = 1 << 33;
	printf("%d\n", i); //0  // warning: left shift count >= width of type

	return 0;
}
