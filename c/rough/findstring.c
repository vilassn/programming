/* program to search a string into another string without using strstr*/
#include<stdio.h>
main()
{
 char a[50],b[20], count=0;
 int i,j,k;
 printf("Enter the first string\n");
 scanf("%s",a);
 printf("enter the string to be search\n");
 scanf("%s",b);
 for(i=0; a[i];i++)
{ 
  j=0;
  if(b[j]==a[i])
  { 
    
      k=i;
    for(j=j+1 ; b[j]; j++)
    {
      k++;    
      if(b[j]!=a[k])
          break;
      
    }
    if(b[j]==0)
     count++;
  }
   
}
printf("'%s' found %d times in the'%s'\n",  b,count,a);
}
