#include<stdio.h>
#include<string.h>
main()
{
 char str[100];
 int k, i, j=0;
 printf("Enter the sentence:\n");
 gets(str);
 //printf("space=%d newline%d null=%d",' ', '\n','\0');
for(i=0; str[i];i++);
j=i-1;
//printf("length is %d",j);
for(i=0; i<j; i++)
{
  k= str[i];
  str[i]=str[j];
  str[j]=k;
  j--;
}

puts(str);
}
  
  
