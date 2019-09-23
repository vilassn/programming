#include <iostream>
#include <stdio.h>
using namespace std;

class A
{
 private: 
 	int i;

 public:
	A()
	{
		printf("Hello1\n");	
	}

	A(int i) //explicit A(int i)
	{
		printf("Hello2\n");	
	}
};

int main()
{
 A *obj = new A();
 A *obj2 = new A(10);

 A obj3;
 A obj4 = 'x';
 return 0;
}
 
