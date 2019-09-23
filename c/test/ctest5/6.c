#include<stdio.h>
struct my_struct
{
 int p:1;
 int q:1;
 int r:6;
 int s:2;
 } bigstruct;
struct my_struct1 
{
 char m:1;
} smallstruct;
 main()
{
 printf("%d %d\n", sizeof(bigstruct), sizeof(smallstruct));
}
