// A simple atoi() function

#include <stdio.h>

int strlen1(char* str) {

	int len = 0;
	for (int i = 0; str[i] != '\0'; i++)
		len++;

	return len;
}

void strrev1(char* str) {

	int len = strlen1(str);
	printf("len: %d\n", len);

	int start = 0;
	int end = len - 1;
	while (start < end) {
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

int atoi1(char *str) {

	int num = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		num = num * 10 + str[i] - '0';
	}

	return num;
}

void itoa1(char *str, int num) {

	int i = 0;
	for (i = 0; num != 0; i++) {
		str[i] = num % 10 + '0';
		num = num / 10;
	}

	str[i] = '\0';
	strrev1(str);
}

int main() {

	char str[10] = { 0 };
	char str1[10] = { 0 };

	printf("Convert string to number: ");
	scanf("%s", str);

	int num = atoi1(str);
	printf("num: %d\n", num);

	itoa1(str1, num);
	printf("string: %s\n", str1);

	return 0;
}

