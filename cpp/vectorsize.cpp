#include <iostream>
#include <vector>
using namespace std;
 
int main() {
   // create a vector to store int
   vector<int> vec; 
   int i;

   // display the original size of vec
   cout << "vector size = " << vec.size() << endl;

   // push 5 values into the vector
   for(i = 0; i < 5; i++)
   {
      vec.push_back(i);
      vec.push_back(i);
   }

   cout << "vector size = " << vec.size() << endl;
   return 0;
}
