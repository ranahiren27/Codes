#include <stdio.h>
#include <stdlib.h>
#define maxLimit 100000

typedef struct item{

  long long int weight;
  long long int cost;
} item ;

item x[maxLimit];

typedef struct knapsackValues
{
    long long int value;
    long long int valueEntered;

} knapsackValue;

long long int maxValue(long long int a,long long int b)
{
    return (a>b)?a:b;
}

long long int maxCost(long long int weight,long long int cost,long long int n,long long int pos )
{



long long int temp;
    if(pos<=0)
    {
        return cost;
    }

    long long int Max;
    if(weight>=x[pos].weight)
    {
        temp=maxValue(maxCost(weight-x[pos].weight,cost+x[pos].cost,n,pos-1),maxCost(weight,cost,n,pos-1));

        return temp;

    }
    else
    {

        return maxCost(weight,cost,n,pos-1);
    }




}


int main()
{
    long long int n;
    printf("Enter the number of items\n");
    scanf("%lld",&n);

    long long int m=0;

    long long int i,w;
    printf("Enter the item weight and costs\n");
    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld",&x[i].weight,&x[i].cost);
        m+=x[i].weight;

    }
    int temp;

    printf("Enter the maximum weight of knapsack\n");
    scanf("%d",&temp);
    while(temp!=0)
    {
     printf("%lld\n",maxCost(temp,0,n,n)) ;
     printf("Enter the maximum weight of knapsack\n");
    scanf("%d",&temp);

    }















return 0;

}
