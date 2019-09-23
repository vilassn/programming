#include<stdio.h>
#include<string.h>
main()
{
  char str1[20],str2[20],str3[20],strr[50];
  int i,j,k;
  printf("enter the strings");
  scanf("%s %s %s", str1,str2,str3);
  for(i=0; str1[i]; i++)
  {
   strr[i]=str1[i];
 } 
 strr[i]=32;
 i++;
 for(j=0; str2[j]; j++)
{
 strr[i]=str2[j];
i++;
}
strr[i]=32;
i++;
for(k=0; str3[k]; k++)
{
 strr[i]=str3[k];
i++;
}
strr[i]='\0';
printf("%s", strr);
}
