#include <stdio.h>
#include <stdlib.h>


int ispal(int a)
{
  int t=0,n=a;
  while(n)
  {
    t=t*10+(n%10);
    n/=10;
  }
   if(t==a)
       return 1;
   else
       return 0;
}
int main()
{
    printf("%d",ispal(1221));
}
