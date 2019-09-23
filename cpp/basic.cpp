/* For compiling: $ c++ 1.cpp */

#include <iostream>
using namespace std;

class Demo
{
 private: 
 	int num;// =2; can't initialize here
	char str[10];
    	static char gstr[10];
 public:
	Demo()
	{
	 cout<<"In "<<__func__<<" Contructor"<<endl;
	}

  	void get()
 	{       
	 cout<<"Enter value of num and str\n";
	 cin>>num>>str;
	}

	void put();
	//~Demo();
};

char Demo::gstr[]="vilas";//initialization of private variable - gstr
int intValue;

void Demo::put()
{
 cout<<"num="<<num<<" str="<<str<<endl;
 cout<<"this->num="<<this->num<<" this->str="<<this->str<<endl;
 cout<<"gstr="<<gstr<<" this->gstr="<<this->gstr<<" intValue="<<intValue<<endl;
}

int main()
{
  cout<<"Vilas "<<"Ninawe, ";
  cout<<"Hyderabad"<<endl<<endl;

  Demo demo;
  demo.get();
  demo.put();
  //cout<<"gstr="<<Demo::gstr<<endl;// error: ‘char Demo::gstr [10]’ is private
  return 0;
}
