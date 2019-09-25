#include<stdio.h>

int main() {

	int a, b = 10, c = 10;

	// printf("space:  %d\n", ' '); //32
	// printf("exclaim:%d\n", '!'); //33
	// printf("newline:%c\n", '\n'); //10
	// printf("amprsnd:%c\n", '@'); //64
	// printf("capitlZ:%c\n", 'Z'); //90

	printf("%d\n", 33 ^ (11 & 1));

	char *str =
			"\
Fy!QJu ROo TNn(ROo)SLq SLq ULo+\
UHs UJq TNn*RPn/QPbEWS_JSWQAIJO^\
NBELPeHBFHT}TnALVlBLOFAkHFOuFETp\
HCStHAUFAgcEAelclcn^r^r\\tZvYxXy\
T|S~Pn SPm SOn TNn ULo0ULo#ULo-W\
Hq!WFs XDt!";

	while (a = str[b + 1]) {
		//printf("Outer: %c\n", a);

		b++;
		while (a > 64) {
			//printf("Inner: %c\n", a);

			a--;
			c++;

			if (c == 90)
				printf("%c", c = 10); //print '\n'
			else
				printf("%c", 33 ^ (b & 1)); // print ' ' or '!'
		}
	}

	return 0;
}

