#include <stdio.h>
#include <stdlib.h>

//ar is the original list of integers
int ar[100];

// id contains the id's (roots) of all elements
int id[100];

//size contains the size i.e no. of elements underneath it
int size[100];

int findRoot(int x)
{
   int temp;
   temp=id[x];
int root=temp;
   while(temp>=0 && temp!=id[temp])
   {
       temp=id[temp];
       if(temp>=0)
       {
           root=temp;
       }
   }



   //applying path compression
   while(x!=root)
   {
       int old = x;
       x=id[x];
       id[old]=root;


   }




//printf("findRoot returns value\n");
   return root;
}



int UnionMerge(int a,int b)
{
    int rootA = findRoot(a);
    int rootB = findRoot(b);

    //printf("The root of %d is %d\n",a,rootA);
    //printf("The root of %d is %d\n",b,rootB);

    if(rootA==rootB)
    {
        return 0;
    }


    //Applying the concept of weighted quick union
    if(size[rootA]>=size[rootB])
    {
        id[rootB]=rootA;
        size[rootA]+=size[rootB];
    }
    else
    {
        id[rootA]=rootB;
        size[rootB]+=size[rootA];
    }


}


int main()
{


    int i;
    for(i=0;i<100;i++)
    {
       ar[i]=i;
       id[i]=i;
       size[i]=0;
    }

while(1)
{


    int check;
    printf("To merge press 1 and to find press 0 :: \n");
    int a,b;
    scanf("%d\n",&check);
    if(check==1)
    {
        scanf("%d %d",&a,&b);
        int f =UnionMerge(a,b);

    }
    else
    {
        scanf("%d",&a);

        printf("The root is %d\n",findRoot(a));

     //   printf("Crossed\n");
    }


}



}
