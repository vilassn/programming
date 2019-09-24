#include <stdio.h>

/*
 * https://www.geeksforgeeks.org/structure-member-alignment-padding-and-data-packing/
 *
 * https://stackoverflow.com/questions/3318410/pragma-pack-effect
 *
 * #pragma pack instructs the compiler to pack structure members with particular alignment.
 * Most compilers, when you declare a struct, will insert padding between members to ensure
 * that they are aligned to appropriate addresses in memory (usually a multiple of the type's size).
 * This avoids the performance penalty (or outright error) on some architectures associated with
 * accessing variables that are not aligned properly.
 *
 * alignment must be power of two
 */

//#pragma pack(1) //valid as power of two
//#pragma pack(2) //valid as power of two
//#pragma pack(3) //invalid as not power of two
//#pragma pack(4) //valid as power of two => default 4
int main() {

	struct struct1 {
		int i :1;
		int j :3;
		int k :2;
	} s1;

	printf("size of struct s1: %d\n", (int) sizeof s1);

	s1.i = 1;
	printf("value of s1.i: %d\n", s1.i);
	//printf("%d\n", sizeof s1.i);  //error: application of ‘sizeof’ to a bit-field

	struct struct2 {
		int i;
		char c;
		int k;
		char d;
	} s2;

	printf("size of struct s2: %d\n", (int) sizeof s2); //16

	struct struct3 {
		int i;
		char c;
		char d;
		char c1;
		char d2;
		int k;
	} s3;

	printf("size of struct s3: %d\n", (int) sizeof s3); //12

//this pragma is effective only for below structures
#pragma pack(1)
	struct x {
		int a :30;
		int b :2;
		char d :3;
		char c :3;
	} x1;

	printf("size of struct x: %d\n", sizeof(x1));

	return 0;
}

