#include <stdio.h>
#include <stdlib.h>

// algorithm to do quick find
int main()
{
    // operating on integers from 1 to 100

    int arr[100];
    int id[100];

    int i;
    for(i=0;i<100;i++)
    {
        arr[i]=i;
        id[i]=i;
    }


    int check;
    int a,b;
    while(1)
    {


    printf("to merge press 1 and to find press 0 ::\n");
    scanf("%d",&check);
    if(check==1)
    {

        scanf("%d %d",&a,&b);

        int rootA = id[a];
        int rootB = id[b];

        for(i=0;i<100;i++)
        {
            if(id[i]==rootB)
            {
                id[i]=rootA;
            }
        }



    }
    else
    {
        scanf("%d",&a);

        printf("the root is %d\n",id[a]);

    }
}


}
