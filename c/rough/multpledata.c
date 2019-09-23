#include<stdio.h>
main()
{
 char str[50];
 int l,k;
 printf("Enter str: ");
 scanf("%s",(str+0));
 l=strlen(str)+1;
 printf("l=%d\n",l);
 printf("Enter str2: ");
 scanf("%s",(str+l));
 k=strlen(str+l)+l+2;
 printf("k=%d\n",k);
 printf("Enter str3: ");
 scanf("%s",(str+k));
 printf("%s %s %s",(str+0),(str+l),(str+k));
}
