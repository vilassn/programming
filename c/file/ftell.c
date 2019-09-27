#include <stdio.h>

int main() {

	long ftel;
	FILE *fp;
	fp = fopen("vilas.c", "r");
	perror("fopen");
	fseek(fp, 0, 2);
//ftel=ftell(fp);
	printf("%d", ftell(fp));

	return 0;
}

