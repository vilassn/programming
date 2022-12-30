#include<iostream.h>
class Obs;
//
  class Subject {
public:
Subject();
   void attach( Obs* );
 void setVal( int );
     int  getVal();
void notify();
private:
     Obs*  obs_[10];
        int   num_, val_;
  };

class Obs { public:
     virtual void update() = 0;
 protected:
 Subject*  sub_;
 int       div_;
                 };
class DivObs : public Obs { public:
          DivObs( Subject*, int );
     void update();
      };
class ModObs : public Obs { public:
     ModObs( Subject*, int );
        void update();
      };

    Subject::Subject()     { num_ = 0; }
  int  Subject::getVal() { return val_; }
   void Subject::attach( Obs* o ) {
   obs_[num_++] = o; }
    void Subject::setVal( int v ) {
     val_ = v;   notify(); }
      void Subject::notify() {
        for (int i=0; i < num_; i++)
           obs_[i]->update(); }
   DivObs::DivObs( Subject* s, int d ) {
    sub_ = s;  div_ = d;
sub_->attach( this ); }
  void DivObs::update() {
                                     int v = sub_->getVal();
          cout << v << " div " << div_
                           << " is " << v / div_ << endl; }
          ModObs::ModObs( Subject* s, int d ) {
               sub_ = s;  div_ = d;
               sub_->attach( this ); }
  void ModObs::update() {
          int v = sub_->getVal();
        cout << v << " mod " << div_
       << " is " << v % div_ << endl; }
       void main( void )
       {
   Subject  subj;
       DivObs   divObs1( &subj, 4 );
                       DivObs   divObs2( &subj, 3 );
                                          ModObs   modObs3( &subj, 3 );
          subj.setVal( 14 );
              }

