#include <stdio.h>
#include <stdlib.h>



int greatestCommonDivisor(int m, int n)
{
    int r;

    /* Check For Proper Input */
    if((m == 0) || (n == 0))
        return 0;
    else if((m < 0) || (n < 0))
        return -1;

    do
    {
        r = m % n;
        if(r == 0)
            break;
        m = n;
        n = r;
    }
    while(1);

    return n;
}


int main()
{
   printf("%d",greatestCommonDivisor(2,4));
}
