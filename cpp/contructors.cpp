#include <iostream>
#include <stdio.h>

using namespace std;

class Calc
{
 private:
 	int real;
	float cmplx;

 public:
	Calc();
	Calc(int, float);
  	Calc(int, float, int, float);
	Calc(Calc&);
	void getdata();
	void setdata(Calc);
	void putdata();
};

Calc::Calc()
{
 cout<<"In default constructor"<<endl;
}

Calc::Calc(int real, float cmplx, int real2, float cmplx2=1000.0)
{
 cout<<"In constructor with default args"<<endl;
 cout<<"real="<<real<<" complex="<<cmplx<<endl;
 cout<<"real2="<<real2<<" complex2="<<cmplx2<<endl;
}

Calc::Calc(int real, float cmplx)
{
 cout<<"In parametrized constructor"<<endl;
 this->real=real;
 this->cmplx=cmplx;
}

Calc::Calc(Calc& calc)//calc is reference of calc2 sent from main(), not another copy
{
 cout<<"In copy constructor"<<endl;
 this->real=calc.real;
 this->cmplx=calc.cmplx;
 calc.cmplx = 100.0; //This change original copy sent from main()
 printf("In %s, calc=%p\n", __func__, &calc);
}

void Calc::getdata()
{
 cout<<"Enter the real and complex values\n";
 cin>>real>>cmplx;
}

void Calc::setdata(Calc calc)//calc is another copy of calc2 sent from main() and it also invoke copy constructor
{
 this->real=calc.real+1;
 this->cmplx=calc.cmplx+1.0;
 calc.cmplx=0;//It doesn't change value of calc2 sent main()
 printf("In %s, calc=%p\n", __func__, &calc);
}

void Calc::putdata()
{
 cout<<"real="<<real<<" complex="<<cmplx<<endl;
}

int main()
{
 Calc calc1, calc2(10, 20.2), calc3(calc2), calc4(1, 2, 3), calc5(1, 2, 3, 4);

 printf("In %s, calc2=%p\n", __func__, &calc2);
 calc1.getdata();
 calc1.putdata();
 calc2.putdata();
 calc3.putdata();
 calc3.setdata(calc2);
 calc3.putdata();
 calc2.putdata();
 return 0;
}
