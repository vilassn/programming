#include <iostream>

using namespace std;

class Calc
{
 private:
 	int real;
	float cmplx;

 public:
	void getdata();
	void setdata(int, float);
	Calc adddata(int);
	Calc adddata(Calc c);
	Calc operator+(Calc c);
	//void operator+(Calc c);//Can't overload "Calc operator+(Calc c)"
	//Calc operator+(Calc c, int);//"Calc operator+(Calc, int)" must take either zero or one argument
	void putdata();
};

void Calc::getdata()
{
 cout<<"Enter the real and complex values\n";
 cin>>real>>cmplx;
}

void Calc::setdata(int obj1, float obj2)
{
 real=obj1;
 cmplx=obj2;
}

Calc Calc::adddata(int val)
{
 Calc res;
 res.real = real + val;
 res.cmplx = cmplx + val;
 return res;
}

Calc Calc::adddata(Calc obj)
{
 Calc res;
 res.real = real + obj.real;
 res.cmplx = cmplx + obj.cmplx;
 return res;
}

Calc Calc::operator+(Calc obj)
{
 Calc res;
 res.real = real + obj.real;
 res.cmplx = cmplx + obj.cmplx;
 return res;
}

void Calc::putdata()
{
 cout<<"real="<<real<<" complex="<<cmplx<<endl;
}

int main()
{
 Calc calc1, calc2, res;

 calc1.getdata();
 res=calc1.adddata(10);
 res.putdata();

 calc2.setdata(10, 20.2);
 res=calc1.adddata(calc2);
 res.putdata();

 res=calc1+calc2;
 res.putdata();

 return 0;
}


