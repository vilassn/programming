/* KTOD: A key to disk program. */
#include <stdio.h>
#include <stdlib.h>
main(int argc, char *argv[]) {
	FILE *fp;
	char ch;
	if (argc != 2) {
		printf("You forgot to enter the filename.\n");
		exit(1);
	}
	if ((fp = fopen(argv[1], "r+")) == NULL) {
		printf("Cannot open file.\n");
		exit(1);
	}

//to write into file
	do {
		ch = getchar(); /*read one character from keyboard*/
		putc(ch, fp); /*write one character into file*/
	} while (ch != '!');

	rewind(fp);
//to read from file
	ch = getc(fp); /* read one character from file*/
	while (ch != EOF) {
		putchar(ch); /* print one character on screen */
		ch = getc(fp); /* read one character from file*/
	}

	fclose(fp);
	return 0;
}
