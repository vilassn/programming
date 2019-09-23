#include<stdio.h>
#define square 1
#define s 0
/* if u are using square in #ifdef no need to initialise 
   u can write as   #define square       only
    but if u are using square in #if then u must initiase it to const
    u must write as   #define square constant_value
main()
{
 int i;
/* #ifdef square && s  //error - extra token to ifdef
 // don't write condition in #ifdef preprocessor
 //just write as          #ifdef square
  printf("vilas");
  #else
  printf("vikas");
#endif*/
#if square && s
  printf("vilas");
 #else
  printf("vikas");
#endif
}
