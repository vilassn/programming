#include<stdio.h>
main()
{
  char str[20];
  gets(str);
  puts(str);
  scanf("%[^\n]s",str);
  printf("%s",str);
}
