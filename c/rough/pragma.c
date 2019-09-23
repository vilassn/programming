#include<stdio.h>
#pragma pack(4)
struct emp
{
 char i;
 int j;
}v;

main()
{
  printf("size of v is %d",sizeof(v));//if pack(1)=>size is 5
                                      //if pack(4)=>size is 8
                                      //default is pack(4)
}
 
