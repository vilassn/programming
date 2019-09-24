#include<stdio.h>

int strcompare(char *str1, char *str2) {

	int i;
	for (i = 0; str1[i] && str2[i]; i++) {

		int k = (str1[i] - str2[i]);
		if (k < 0)
			return -1;
		else if (k > 1)
			return 1;
	}

	if (str1[i] == '\0' && str2[i] == '\0')
		return 0;
	else if (str1[i] == '\0')
		return -1;
	else
		return 1;
}

int main() {

	char str1[20], str2[20];
	int res;

	printf("Enter the string 1: ");
	scanf("%s", str1);

	printf("Enter the string 2: ");
	scanf("%s", str2);

	res = strcompare(str1, str2);

	if (res > 0)
		printf("str1 is greater than str2");
	else if (res < 0)
		printf("str1 is less than str2");
	else
		printf("str1 is equal to str2");

	return 0;
}

