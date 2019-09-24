#include <stdio.h>
/*
 * Byte ordering:
 *
 * In TCP/IP, this is generally Big Endian.
 *
 * Big Endian: This means most significant byte in the smallest address in a word.
 * Littel Endian: This means least significant byte in the smallest address in a word.
 *
 * for example, num 0x01234567 will be stored as
 *
 * address: 0x100 0x101 0x102 0x103
 * Big E  : 01    23    45    67     (msb at small address)
 * Lit E  : 67    45    23    01     (lsb at small address)
 *
 * In union, small memory address will be given to small member
 * int address  => 0x100 0x101 0x102 0x103
 * char address => 0x100
 */
union {
	char ch; //
	int num; //
} uni;

struct {
	char ch;
	int num;
} struc;

int main() {

	uni.num = 0x00000001;

	printf("uni.ch: %u\n", uni.ch);

	//check what is in small memory address
	//if it is lsb, then little endian
	if (uni.ch == 0x01)
		printf("Little Endian\n");
	else
		printf("Big Endian\n");

	printf("sizeof uni=%lu, sizeof struc=%lu\n", sizeof(uni), sizeof(struc));

	//Another way

	int num = 1;
	char*ch = (char*) &num;
	if (ch[0] == 1)	//if (*ch == 1)
		printf("Little Endian\n");
	else
		printf("Big Endian\n");

	return 0;
}
