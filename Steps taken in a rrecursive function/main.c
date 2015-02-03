#include <stdio.h>
#include <stdlib.h>

void steps(int x,int steps_taken)
{
    if(x/2==0)
    {
        printf("%d",steps_taken+1);

    }
    else
    {
        steps(x/2,steps_taken+1);
    }


}


int main()
{
    int x;
    scanf("%d",&x);

    steps(x,0);
}
