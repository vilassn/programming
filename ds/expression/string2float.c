#include<stdio.h>
float str2float(char *);
main() {
	char str[20];
	printf("Enter the string: ");
	scanf("%s", str);
	printf("\nResult=%f", str2float(str));
	return 0;
}

float str2float(char *str) {
	int i, res = 0, flag = 0, state = 1;
	float fract = 0, result;
	for (i = 0; str[i]; i++) {
		if (str[i] != '.') {
			if (state == 1)
				res = (str[i] - 48) + res * 10;
			else {
				flag++;
				fract = (str[i] - 48) + fract * 10;
			}
		} else
			state = 0;
	}
	while (flag--)
		fract = fract / 10;
	result = res + fract;
	return result;
}

