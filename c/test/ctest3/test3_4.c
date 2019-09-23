#include<stdio.h>
#include<string.h>
main()
{
 while(strcmp("some","some\0"))
printf("strings are not equal\n");
}
