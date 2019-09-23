#include<stdio.h>
struct tag1 {
	int a;
	char b[12];
	float c;
} main() {
	struct tag1 v1 = { 11, a, "vector" };
	printf("%d %s %f", v1.a, v1.b, v1.c);
}
