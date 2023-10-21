#include <stdio.h>
#include <string.h>

int strlen1(char* str);
char *reverse(char* str);

int main()
{
	char str[20];
	printf("enter string\n");
	scanf("%s", str);
	int len = strlen(str);
	printf("len: %d\n", len);
	
	len = strlen1(str);
	printf("len: %d\n", len);
	
	char* revstr = reverse(str);
	printf("%s\n", revstr);
	
	return 0;
}

char *reverse(char* str){
	int len = strlen(str);
	for (int i=0; (i < len/2); i++)
	{
		char temp = str[i];
		str[i] = str[len-i-1];
		str[len-i-1]=temp;
	}
		
	return str;
}

int strlen1(char* str)
{
	int i = 0;
	while(str[i] != '\0'){
		i++;
	}
	
	return i;
}
