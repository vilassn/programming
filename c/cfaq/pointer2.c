#include <stdio.h>

// Declare fptr_t as pointer to function (float) returning pointer to function (char) returning int
//
// int(*(*fptr_t)(float))(char) 
//

main()
{
 const int x=0;
 const int *p;
 //int *p;

 p=&x;
 func(p);
 //*p=55;

 printf("x=%d\n", x);
 
 /*****************************/

 int *intptr = 0x1000;
 void *voidptr=intptr;

 intptr++;  //Increments by 4 bytes
 voidptr++; //Increments by 1 byte

 printf("intptr=%p, voidptr=%p\n", intptr, voidptr);
}

func(int *p)
{
 *p=55;
}
