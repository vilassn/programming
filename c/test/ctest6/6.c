#include<stdio.h>
main()
{
 char *str;
 str=(char)malloc(20*sizeof(char));
 strcpy(str,"test");
 strcat(str,'!');
 printf("%s",str);
}
