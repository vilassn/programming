#include <iostream>
using namespace std;
class A
{
	public:
	A()
	{
		cout<<"const\n";
	}
	void hi (A a1)
	{
		cout<<"hi fun\n";
	}
	~A()
	{
		cout<<"destructor\n";
	}
};
main()
{
	A b1;
	b1.hi(b1);
}

//OP:
//const
//hi fun
//destructor
//destructor

