#include <iostream>
using namespace std;

class Component { public:
   virtual ~Component() { }
   virtual void doIt() = 0;
};

class Window : public Component { public:
   ~Window() { cout << "Window dtor" << '\n'; }
   /*virtual*/ void doIt() { cout << "Window"; }
};

class Deco : public Component {
   Component* wrappee;
public:
   Deco( Component* inner )           { wrappee = inner; }
   ~Deco()                    { delete wrappee; }
   /*virtual*/ void doIt() { wrappee->doIt(); }
};

class DecoX : public Deco { public:
   DecoX( Component* core ) : Deco(core) { }
   ~DecoX() { cout << "DecoX dtor" << "   "; }
   /*virtual*/ void doIt() { Deco::doIt();  cout <<"Deco X"; }
};

class DecoY : public Deco { public:
   DecoY( Component* core ) : Deco(core) { }
   ~DecoY() { cout << "DecoY dtor" << "   "; }
   /*virtual*/ void doIt() { Deco::doIt();  cout << 'Y'; }
};

class DecoZ : public Deco { public:
   DecoZ( Component* core ) : Deco(core) { }
   ~DecoZ() { cout << "DecoZ dtor" << "   "; }
   /*virtual*/ void doIt() { Deco::doIt();  cout << 'Z'; }
};

void main( void ) {
   Component* anX = new DecoX( new Window );
   Component* anXY = new DecoY( new DecoX( new Window ) );
   Component* anXYZ = new DecoZ( new DecoY( new DecoX( new Window ) ) );
   anX->doIt();    cout << '\n';
   anXY->doIt();   cout << '\n';
   anXYZ->doIt();  cout << '\n';
   delete anX;   delete anXY;   delete anXYZ;
}
