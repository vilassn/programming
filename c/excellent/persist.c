#include<stdio.h>
#include<malloc.h>
#include<string.h>
main() {
	FILE *fp;
	char ch = 0, str[100][20], *file, *addr, *ptr;
	int i = 0, j = 0, k = 0, count[100] = { 0 }, index = 0;
	file = (char *) malloc(1000);
	fp = fopen("vilas.txt", "r");
	if (fp == 0) {
		printf("Error while opening the file");
		return 0;
	}
	while ((ch = fgetc(fp)) != EOF) {
		file[i] = ch;
		i++;
	}
	file[i] = '\0';
	i = 0;
	printf("%s\n", file);
	while (ch != '\0') {
		ch = file[i];
		if ((ch == ' ')) //|| (ch=='\0'))
		{
			str[j][k] = '\0';
			addr = &file[i - strlen(str[j]) - 1];
			index = 0;
			k = 0;
			while (1) {
				if (ptr = strstr(file + index, str[j])) {
					if (ptr <= addr) {
						break;
					}
					count[j] = count[j] + 1;
					index = ptr - file + strlen(str[j] + 1);
				} else {
					j++;
					break;
				}

			}
		}
		str[j][k] = ch;
		i++;
		k++;
	}
	for (i = 0; i < j; i++) {
		printf("%s\tfound \t%d times\n", str[i], count[i]);
	}
}
