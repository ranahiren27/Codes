#include <stdio.h>
#include <stdlib.h>

int main()
{

    int prime[400]={0};
    prime[0]=2;
    prime[1]=3;
    int i,j,count=2,remain=0;;
    for(i=5;i<2001;i=i+2)
    {
        remain=0;
        for(j=1;j<count;j++)
        {
            if(i%prime[j]!=0)
            {

                remain++;

            }
        }

        if(remain==count-1)
        {
          prime[count]=i;
        count++;
        }
    }

    int t;
    scanf("%d",&t);
    int x,y;
    while(t--)
    {
        scanf("%d %d",&x,&y);
        int sum=x+y;
        int primeIndex=0;
        for(i=0;i<350;i++)
        {
            if(sum<prime[i])
            {
                primeIndex=i;
                break;
            }
        }
        int balance = prime[primeIndex] - sum;
        if(balance==0)
        {
            balance=prime[primeIndex+1] - sum;
        }
        printf("%d\n",balance);
    }

    return 0;


}
