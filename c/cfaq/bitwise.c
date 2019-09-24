#include <stdio.h>

printbitschar(char num) {

	printf("Bin: ");

	for (int bitpos = 7; bitpos >= 0; bitpos--)
		(num & (1 << bitpos)) ? printf("1") : printf("0");

	printf(" Dec: %d\n", num);
}

printbitsint(int num) {

	printf("Bin: ");

	for (int bitpos = 31; bitpos >= 0; bitpos--)
		(num & (1 << bitpos)) ? printf("1") : printf("0");

	printf(" Dec: %d\n", num);
}

complement(char num) {

	//0b00011000
	printbitschar(num);

	//TODO: write complementing code
}

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

//////////////////////////////////////
	signed char ch = 0b00000001 << 7; //-128
	printbitschar(ch);

	ch = 0b10000000 >> 7; //1
	printbitschar(ch);

	ch = -0b10000000 >> 7; //-1
	printbitschar(ch);

	printbitschar(0b11100111 & 0b00000111);
	printbitschar(0b11100011 | 0b00000111);

	complement(0b00011000);

	return 0;
}
