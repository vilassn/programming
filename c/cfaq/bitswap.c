#include <stdio.h>

void printbits(char num) {

	printf("0x");

	for (int i = 7; i >= 0; i--) {
		int bit = num >> i & 1;
		printf("%s", (bit == 1) ? "1" : "0");
	}

	printf("\n");
}

void swapnibbles(char ch) {

	ch = ((ch >> 4) & 0b00001111) | ((ch << 4) & 0b11110000);
	printbits(ch);
}

unsigned char swapbits(unsigned char n, unsigned char pos1, unsigned char pos2) {

	//if n=10000001
	unsigned char mask1 = 0x01 << pos1; //00000001
	unsigned char mask2 = 0x01 << pos2; //10000000

	int bitatpos1 = (n & mask1) ? 1 : 0;
	int bitatpos2 = (n & mask2) ? 1 : 0;

	if (bitatpos1 != bitatpos2)
		n = n ^ (mask1 | mask2);  //10000000 ^ 10000001 = 10001000
	else
		printf("bits are same\n");

	return n;
}

char swapallbits(char num) {

	int start = 0;
	int end = 7;
	while (start < end) {

		unsigned char mask1 = 0x01 << start;
		unsigned char mask2 = 0x01 << end;

		int bitatpos1 = (num & mask1) ? 1 : 0;
		int bitatpos2 = (num & mask2) ? 1 : 0;

		if (bitatpos1 != bitatpos2)
			num = num ^ (mask1 | mask2);

		start++;
		end--;
	}

	return num;
}

int main() {

	char ch = -127;

	printf("A-Z=%d-%d, a-z=%d-%d, 0-9=%d-%d\n", 'A', 'Z', 'a', 'z', '0', '9');

	// & operator has high priority than ^
	printf("%d\n", 33 ^ 11 & 1); // 33 ^ (11 & 1)

	/*
	 * signed char range => -128 to 127
	 * unsigned char range => 0 to 255
	 *
	 * bit: 7   6  5  4  3  2 1 0
	 * wtg: 128 64 32 16 8  4 2 1
	 *
	 * -ve no. is 2's complement of +ve no.
	 *
	 * suppose, signed ch = -128
	 *
	 * 128 in binary 0x10000000
	 * 128 => 1's complement => 0x01111111
	 * 128 => 2's complement => 1's complement + 1
	 *
	 *        0x01111111
	 *      + 0x00000001
	 * -----------------------
	 *        0x10000000 => -128
	 *
	 *
	 * suppose, signed ch = -129
	 *
	 * 129 in binary 0x10000001
	 * 129 => 1's complement => 0x01111110
	 * 129 => 2's complement => 1's complement + 1
	 *
	 *        0x01111110
	 *      + 0x00000001
	 * -----------------------
	 *        0x01111111 => 127
	 *
	 * so, -129 is stored as 127
	 */

	printf("%d\n", 233);  //decimal no.
	printf("%d\n", 0b110);  //binary no.
	printf("%d\n", 011);  //octal no.
	printf("%d\n", 0xff);  //hex no.
	printf("\n");

	printf("ascii: %c, decimal: %d \n", ch, ch);

	printf("bits:\n");
	printbits(ch);

	printf("right shift 2 bits:\n");
	printbits(ch >> 2);

	printf("left shift 2 bits:\n");
	printbits(ch << 2);

	printf("swap nibbles:\n");
	swapnibbles(ch);

	printf("swap 0 and 7 bits of 0b10000000 \n");
	unsigned char res = swapbits(0b10000000, 0, 7);
	printbits(res);

	printf("swap 0 and 7 bits of 0b10000001 \n");
	unsigned char res2 = swapbits(0b10000001, 0, 7);
	printbits(res2);

	printf("swap all bits of 0b10101011\n");
	unsigned char res1 = swapallbits(0b10101011);
	printbits(res1);
}
