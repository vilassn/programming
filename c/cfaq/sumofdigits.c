#include <stdio.h>
int main()
{
  int n, r, sum=0;
  printf("Enter an integer: ");
  scanf("%d", &n);
  while(n!=0)
  {
      r= n%10;
      n/=10;     /* n=n/10 */
      sum+=r;
  }
  printf("sum of digits: %d",sum);
}
