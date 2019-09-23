                                      
#include <stdio.h>                   
                                      
int  main(void)
{                                      
     int   ch;
                                     
     while((ch = getchar()) != EOF)   
           printf("read '%c'\n", ch);                                       
     printf("EOF\n");
                                      
     return 0;                        
}                                     
                                                                           
