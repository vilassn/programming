#include <iostream>
using namespace std;

template <class T>
class Compare
{
 private:
	T a, b;

 public:
	Compare(T first, T second)
	{
	 a=first;
	 b=second;
	}

	T getmin()
	{
	 T retval;
	 retval=a<b?a:b;
	 return retval;
	}

	T getmax();
};

template <class T>
T Compare <T>::getmax()
{
 T retval;
 retval=a>b?a:b;
 return retval;
}

main()
{
 Compare <int> obj(100, 500);
 cout<<obj.getmin()<<endl;
 cout<<obj.getmax()<<endl;
 cout<<endl;
}
