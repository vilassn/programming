#include<stdio.h>
typedef struct vilas {
	int a;
	int b;
} sample;

main() {
	sample s;
	char str[10];
	scanf("%d %d %s", &s.a, &s.b, str);
	printf("%d %d %p %p", s.a, s.b, str, &str);
}

