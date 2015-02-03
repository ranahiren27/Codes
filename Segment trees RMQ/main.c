#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int minVal(int a,int b)
{
    return a<b?a:b;
}

int Getmid(int a ,int b)
{
    return a + (b-a)/2;
}


int constructSTUtil(int arr[],int ss,int se,int *st,int si)
{
    //if we reach one of the endpoints i.e Leaf node represent inpuut of the array
    if(se==ss)
    {
        st[si]=arr[se];
        return arr[se];
    }

    //if more than one elements are present under the node then store the minimum of left and right subtrees and store it at the index
    int mid = Getmid(ss,se);
    st[si]=minVal(constructSTUtil(arr,ss,mid,st,si*2+1),constructSTUtil(arr,mid+1,se,st,si*2+2));

    return st[si];


}

int *constructST(int arr[],int n)
{
    int x=(int)(ceil(log(n)/log(2)));
    int maxSize=2*(int)pow(2,x)-1;

    printf("max size is %d",maxSize);

    int ST[maxSize];

    constructSTUtil(arr,0,n-1,ST,0);


    //Printing the segment tree created
    /*
    int i;

    for (i=0;i<maxSize;i++)
    {
        printf("%d ",ST[i]);
    }
*/
    return ST;

}

int RMQUtil(int *st,int ss,int se,int qs,int qe,int index)
{
    if(qs<=ss && qe>=se)
    {
        return st[index];
    }

    if(qs>se || ss>qe)
    {
        return INT_MAX;
    }

    int mid =Getmid(ss,se);
    return minVal(RMQUtil(st,ss,mid,qs,qe,2*index+1),RMQUtil(st,mid+1,se,qs,qe,2*index+2));



}


int RMQ(int *st,int n,int qs,int qe)
{
    int a= RMQUtil(st,0,n-1,qs,qe,0);

    printf("%d",a);
}

int main()
{
    int ar[]={2,5,1,4,9,3};

    int n=6;
    int *st=constructST(ar,n);
    RMQ(st,n,3,5);








}
