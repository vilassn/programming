#include<stdio.h>
#include<unistd.h>
main() {
	FILE *fp;
	int size, i = 0;
	char *buf, str1[20], ch;

	fp = fopen("sample", "r");
	fseek(fp, 0, 2);
	buf = malloc(ftell(fp));
	rewind(fp);

	while ((ch = fgetc(fp)) != EOF)
		buf[i++] = ch;

	buf[i] = '\0';
	printf("%s", buf);
	printf("\nEnter the word to search");
	scanf("%s", str1);
	index = 0;
	count = 0;
	while () {
		ptr = strstr(buf + index, str1);
		count++;
	index=ptr-buf+

}

