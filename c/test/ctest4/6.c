#include<stdio.h>
main()
{
 int i, argc;
 char *arg[3]={"abcde", "fghij", "klmno"};
char **argv=arg;
i=argc=3;
while(++argv,--argc,--i)
 printf("%s\n", *argv);
}
