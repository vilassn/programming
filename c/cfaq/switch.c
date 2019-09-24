#include<stdio.h>
main()
{
 int i=1, j=5;
 switch(i)
 {
  case j:printf("vilas"); //error: case label does not reduce to an integer constant
         break;
  case 1: pritnf("vijay");
 }
}
