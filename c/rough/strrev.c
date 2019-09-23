#include<stdio.h>
#include<strings.h>
main()
{
 char str[]="vilas";
 strrevv(str);
 printf("%s",str);
}
 
strrevv(char *p)
{
 int i=0,j=strlen(p);
 char temp;
 
 while(i!=j)
 {
  temp=p[i];
  p[i]=p[j];
  p[j]=temp;
  i++;
  j--;
 }
}
