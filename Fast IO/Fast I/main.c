#include <stdio.h>
#include <stdlib.h>
#define ITYPE unsigned int
#define GETCHAR getchar_unlocked;
#define DIG( a ) ( ( ( a ) >= '0' ) && ( ( a ) <= '9' ) )

void scan_positive_int(long long int *a)
{
        long long int x=0;
        register long long int c=getchar();
        for(; c>47 && c<58 ; c = getchar())
        {
                x = (x<<1) + (x<<3) + c - 48;
        }
        *a=x;
}
int main()
{
    long long int t;
    scan_positive_int(&t);

   printf("%lld",t);

   return 0;
}
