#include<stdio.h>

int main() {

	int a, b = 10, c = 10;

	printf("vilas\n");

	char *str =
			"\
Fy!QJu ROo TNn(ROo)SLq SLq ULo+\
UHs UJq TNn*RPn/QPbEWS_JSWQAIJO^\
NBELPeHBFHT}TnALVlBLOFAkHFOuFETp\
HCStHAUFAgcEAelclcn^r^r\\tZvYxXy\
T|S~Pn SPm SOn TNn ULo0ULo#ULo-W\
Hq!WFs XDt!";

	while (a = str[b++ + 1]) {
		//printf("Outer: %c\n", a);

		while (a-- > 64) {
			//printf("Inner: %c\n", a);

			putchar((++c == 'Z') ? (c = c / 9) : (33 ^ b & 1));
		}
	}

	return 0;
}

