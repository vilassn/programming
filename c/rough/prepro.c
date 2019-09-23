#define g(a,b) a+b
#define h(a,b) a+b
main()
{
  int i,j;
  i=h(2,g(3,4));
  printf("%d",i);
}
