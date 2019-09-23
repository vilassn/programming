#include<stdio.h>
struct num
{
 int no;
char name[25];
};
main()
{
 struct num n1[]={{25,"rose"},{20,"gulmohar"},{8,"geranium"},{11,"dahalia"}};
printf("%d%d",n1[2].no, (*&n1+2)->no+1);
} 
