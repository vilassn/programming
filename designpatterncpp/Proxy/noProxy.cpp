#include <iostream>
#include <string>
using namespace std;

class Image {
   int        id;
   static int next;
public:
   Image() { id = next++;  cout << "   $$ ctor: "<< id << '\n'; }
   ~Image()              { cout << "   dtor: " << id << '\n'; }
   void draw()           { cout << "   drawing image " << id << '\n'; }
};
int Image::next = 1;

void main( void ) {
   Image images[5];
   int   i;

   cout << "Exit[0], Image[1-5]: ";
   cin >> i;
   while (i) {
      images[i-1].draw();
      cout << "Exit[0], Image[1-5]: ";
      cin >> i;
}  }

