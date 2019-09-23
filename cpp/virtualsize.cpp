#include <iostream>
#include <stdio.h>
#pragma pack(1) //64-bit Linux has 8bytes alignment
using namespace std;

struct demo
{

};

class A
{

};

class emp
{
  public:
  	virtual  void read()
  	{

 	}

	virtual void write()
	{

 	}
};
 
class emp1
{
 //int a;
  public:
  	virtual  void read()
  	{

 	}

	virtual void write()
	{

 	}
};

main()
{
 A a;
 emp e;
 emp1 e1;
 demo d;
 int *i;
 printf("%lu\n", sizeof i);
 printf("size of A=%lu, a=%lu\n", sizeof(A), sizeof(a));
 printf("size of demo=%lu, d=%lu\n", sizeof(demo), sizeof(d));
 printf("size of emp=%lu, e=%lu\n", sizeof(emp), sizeof(e));
 printf("size of emp1=%lu, e1=%lu\n", sizeof(emp1), sizeof(e1));
}
//Output:
//8
//size of demo=1, d=1
//size of emp=8, e=8
//size of emp1=8, e1=8
