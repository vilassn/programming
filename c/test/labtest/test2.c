#include<stdio.h>
#include<string.h>
main() {
	int i, j, len;
	char strr[20], str[20], temp;
	printf("Enter the string: ");
	scanf("%s", str);
	len = strlen(str);
	for (i = 0; i <= len - 2; i++) {
		for (j = i + 1; j <= len - 1; j++) {
			if (str[i] > str[j]) {
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}

	j = 0;
	for (i = 0; i <= len - 1; i++) {
		if (str[i] == str[i + 1])
			;
		else {
			str[j] = str[i];
			j++;
		}
	}
	str[j] = '\0';

	printf("%s", str);
}
