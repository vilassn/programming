//http://www.codeproject.com/Articles/541067/Cplusplus11-Smart-Pointers
class Test
{
public:
 Test(int a = 0 ) : m_a(a)
 {
 }
 ~Test( )
 {
  cout<<"Calling destructor"<<endl;
 }
public:
 int m_a;
};
 
void main( )
{
 std::auto_ptr<Test> p( new Test(5) ); 
 cout<<p->m_a<<endl;
}
