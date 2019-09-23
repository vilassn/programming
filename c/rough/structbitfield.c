#include<stdio.h>
#pragma pack(1)
struct x {
	int a :30;
	int b :2;
	char d :3;
	char c :3;
} x1;

main() {
	printf("%d", sizeof(x1));
}
