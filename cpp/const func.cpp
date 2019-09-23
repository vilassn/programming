#include <stdio.h>

class A
{
 private:
  int mFlag;
 public:
 void func(int i, int &j)      //=> This can allowed to change mFlag
// void func(int i, int &j) const  //=> This doesn't allowd to change mFlag 
 {
  j = i + 1; 
  mFlag++;
  printf("In func, %d\n", i);
 }
};

int main()
{
 A a;
 int i = 4, j;
 a.func(i, j);
 printf("In Main, %d\n", j);
 return 0;
}
