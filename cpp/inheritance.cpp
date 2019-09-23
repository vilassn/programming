#include <iostream>
using namespace std;

class A
{
 public:
	A()
	{
	 cout<<"In A()"<<endl;
	}

	A(int a)
	{
	 cout<<"In A(int)"<<endl;
	}
};

class B
{
 public:
	B()
	{
	 cout<<"In B()"<<endl;
	}

	B(int a)
	{
	 cout<<"In B(int)"<<endl;
	}
};


class C: public A
{
 public:
	C()
	{
	 cout<<"In C()"<<endl;
	}

	//C(int a) //will call A()
	C(int a):A(a) //will call A(a)
	{
	 cout<<"In C(int)"<<endl;
	}
};

class D: public B, public A //In same order base class constructor invoke
{
 public:
	D()
	{
	 cout<<"In D()"<<endl;
	}

	D(int a):B(a),A(a)// This sequence doesn't matter for order of base class constructor invokation
	{
	 cout<<"In D(int)"<<endl;
	}
};

class E: public B, virtual A //virtual base class constructor invoke first
{
 public:
	E()
	{
	 cout<<"In E()"<<endl;
	}

	E(int a):B(a),A(a)
	{
	 cout<<"In E(int)"<<endl;
	}
};

int main()
{
 C objc(5);
 cout<<endl;
 D objd(5);
 cout<<endl;
 E obje(5);

 return 0;
}
