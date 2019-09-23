#include<stdio.h>
main()
{
 char str[30];
 int i,j;
 printf("Enter the string: ");
 gets(str);
 for(i=0; str[i]; i++)
 {
  if(str[i]==' ')
  {
   for(j=i; str[j]; j++)
    str[j]=str[j+1];
  }
 }
 printf("string without spaces is %s\n",str);
}
