#include<stdio.h>

main() {

	FILE *fp;
	char ch[] = "\nhi";
	int ch1, ch2, ch3, ch4;

	fp = fopen("bin", "wb+");
	fwrite(ch, 4, 1, fp);
	fclose(fp);

	fclose(fp);
}

