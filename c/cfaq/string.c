#include <stdio.h>
#include <string.h>

char* strfunc() {

	char string[] = "vilas";
	//return string; //warning: function returns address of local variable //output null

	char *ptr = (char*) malloc(10);
	strcpy(ptr, "vilas");
	return ptr;
}

void stringop() {

	int l, k;
	char str[50];

	printf("Enter str: ");
	scanf("%s", (str + 0));

	l = strlen(str) + 1;

	printf("l=%d\n", l);
	printf("Enter str2: ");
	scanf("%s", (str + l));

	k = strlen(str + l) + l + 2;

	printf("k=%d\n", k);
	printf("Enter str3: ");
	scanf("%s", (str + k));

	printf("%s %s %s", (str + 0), (str + l), (str + k));
}

int main() {

	char str[10] = "vector"; //data section - rw memory
	char *ptr = "institute"; //code section read only memory

	strcpy(str, ptr);
	printf("str=%s\n", str);

	// strcpy(ptr, str); //segfault
	printf("ptr=%s\n", ptr);

	// ptr[0]-=32; //seg fault
	printf("ptr=%s\n", ptr);

	ptr = str;
	ptr[0] -= 32;
	str[1] -= 32;
	printf("%s\n", str);

	char *p[] = { "vilas", "vikas", "bhau" };
	printf("%s\n", p[2]);

	char *ptr1 = "vilasninawe";
	char s[] = "vilasninawe";

	printf("%d %d %d %d\n", strlen(s), sizeof(s), strlen(ptr1), sizeof(ptr1));

	printf("strfunc ret: %s\n", strfunc()); //null

	stringop();

//////////////////////////////////////////

	char str5[20];
	gets(str5);
	puts(str5);
	scanf("%[^\n]s", str5);
	printf("%s", str5);
}
