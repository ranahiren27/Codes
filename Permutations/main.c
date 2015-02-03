#include <stdio.h>
#include <stdlib.h>
int fact(int a)
{
    int x=1;
    if(a==1)
    {
        return 1;
    }
    else
    {
        x=a*fact(a-1);
        return x;
    }
}
int main()
{
    printf("Enter the number  of digits\n");
    int count,i;
    scanf("%d",&count);
    printf("Enter the digits\n");
    int digits[count];
    for(i=0;i<count;i++)
    {
        scanf("%d",&digits[i]);
    }

    printf("%d",fact(4));
    printf("%d",fact(5));
    return 0;
}
