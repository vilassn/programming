#include<stdio.h>
#include<string.h>
main()
{
 char str[60],ch;
 int i,j, flag=0,k,temp;
 printf("enter the string: ");
 gets(str);//  "vilas is boy"
 strrev(str);
 i=0;j=0;
 while(str[i])
 {
  ch=str[i];
  if(ch==' ')
     {
       for(j=flag, k=i; j<k; j++, k--)
          {
           temp=str[j];
           str[j]=str[k];
           str[k]=temp;
          }
           if(ch=='\0')
              break;
       flag=i+1;
      }
   i++;
 }
 printf("%s",str);
}

strrev(char *p)
{
 int i=0,j=strlen(p)-1;
 char temp;
 
 while(i<j)
 {
  temp=p[i];
  p[i]=p[j];
  p[j]=temp;
  i++;
  j--;
 }
}
