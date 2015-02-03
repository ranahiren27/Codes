#include <stdio.h>
#include <stdlib.h>
#define limit 1400LL

long long  int prime[limit];


//limit can be used for values greater than 1000LL too. But it takes a lot of time to display the entire result

int main()
{
/*
    long long int i=0;
    for(i=0;i<limit;i++)
    {
        prime[i]=i;
    }

    for(i=0;i<limit;i++)
    {
        printf("%d  ",prime[i]);
    }
*/

    prime[0]=2;



    long long int k=0;
    long long int i=3;
    long long int counter=1;
    while(counter<limit)
    {
        int isPrime=1;
        for(k=0;k<counter;k++)
        {
            if(i%prime[k]==0)
            {
                isPrime=0;
                break;
            }


        }

        if(isPrime==1)
        {
            prime[counter]=i;
            printf("%lld ",prime[counter]);
            counter++;

        }

        i++;
    }

/*
    for(k=0;k<limit;k++)
    {
        printf("%lld  ",prime[k]);
    }

  */
}
