

#include<iostream.h>
#include<vector>
using namespace std;

class Color{
protected:
int red;
int green;
int blue;

public:
	virtual Color* clone()=0;
	virtual void disp()=0;
};

class Factory {
public:
   static Color* make_Color( int choice );
private:
   static Color* color_prototypes[3];
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

	Color *pink=Factory::make_Color(1);
	pink->disp();
	Color *c2=Factory::make_Color(2);
	c2->disp();
	Color *c3=Factory::make_Color(3);
	c3->disp();

   return 0;
}

class Voilet : public Color {
public:
	Voilet(){
	red=200;
	green=100;
	blue=100;
	}
   Color*   clone() { return new Voilet(*this); }
   void disp() {
      cout << "This is Voilet\n"; }
  };

class Magenta : public Color {
public:
   Color*   clone() { return new Magenta (*this); }
   void disp() {
      cout << "This is Magenta\n"; }
};

class Pink : public Color {
public:
	
   Color*   clone() { return new Pink(*this); }
   void disp() {
      cout << "This is Pink\n"; }
};



Color* Factory::color_prototypes[] = {new Voilet(), new Magenta, new Pink()};
Color* Factory::make_Color( int choice ) {
   return color_prototypes[choice-1]->clone();
}
