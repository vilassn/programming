#include<iostream.h>
#include<vector>
using namespace std;
class Cartoon {
public:
   virtual Cartoon* clone() = 0;
   virtual void disp() = 0;
};

class Factory {
public:
   static Cartoon* make_Cartoon( int choice );
private:
   static Cartoon* s_prototypes[3];
};


int main( void ) {
 /*  vector<Cartoon*> roles;
   int             choice;

   while (true) {
      cout << "Dilbert(1) Calvin(2) Chaplin(3) Go(0): ";
      cin >> choice;
      if (choice == 0)
         break;
      roles.push_back(
         Factory::make_Cartoon( choice ) );
   }

   for (int i=0; i < roles.size(); ++i)
      roles[i]->disp();
   for ( i=0; i < roles.size(); ++i)
      delete roles[i];*/

	Cartoon *c1=Factory::make_Cartoon(1);
	c1->disp();
	Cartoon *c2=Factory::make_Cartoon(2);
	c2->disp();
	Cartoon *c3=Factory::make_Cartoon(3);
	c3->disp();

   return 0;
}

class Dilbert : public Cartoon {
public:
	
   Cartoon*   clone() { return new Dilbert(*this); }
   void disp() {
      cout << "This is Dilbert\n"; }
  };

class Calvin : public Cartoon {
public:
   Cartoon*   clone() { return new Calvin (*this); }
   void disp() {
      cout << "This is Calvin\n"; }
};

class Chaplin : public Cartoon {
public:
	
   Cartoon*   clone() { return new Chaplin(*this); }
   void disp() {
      cout << "This is Chaplin\n"; }
};



Cartoon* Factory::s_prototypes[] = {new Dilbert, new Calvin, new Chaplin()};
Cartoon* Factory::make_Cartoon( int choice ) {
   return s_prototypes[choice-1]->clone();
}
