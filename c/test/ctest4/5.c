#include<stdio.h>
func(int i) 
{ 
 if (i%2) 
return 0;
else
 return 1;
} 
main()
{
  int i=3;
 i=func(i);
i=func(i);
printf("%d", i);
}
