#include<stdio.h>
main() 
{
 char thought[2][30]={"Don't walk in front of me..","I am not follow"};
printf("%c%c",*(thought[0]+9),*(*(thought+0)+5));
}
