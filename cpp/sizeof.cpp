
#include<stdio.h> 

int main() 
{ 
    double x; 

    double *p=&x;
    double *p2=p+1;
    printf("%p, %p, size:%ld\n", p, p2, (char*)p2-(char*)p);

    return 0; 
} 

