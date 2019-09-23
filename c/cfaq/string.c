#include <stdio.h>

int (*p)(int i); //pointer to fn accepting int and return int

int print(int i)//funtion accepting int and return int
{
 printf("print %d\n\n", i);
}

int main()
{
 char str[10]="vector";//data section - rw memory
 char *ptr="institute";//code section read only memory
p=print; 
p(5);
 strcpy(str, ptr);
 printf("str=%s\n",str);
// strcpy(ptr, str);
 printf("ptr=%s\n",ptr);
// ptr[0]-=32; //seg fault
 printf("ptr=%s\n",ptr);
 ptr=str;
 ptr[0]-=32;
 str[1]-=32;
 printf("%s\n", str);
}
