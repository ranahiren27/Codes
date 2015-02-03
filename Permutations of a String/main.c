#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter the no of numbers");
    int n;
    scanf("%d",&n);

    int a[n];
    int i;

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }


    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }

}
