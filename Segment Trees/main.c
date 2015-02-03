#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int getMid(int s,int e)
{
    return s + (e-s)/2;
}

/*  A recursive function to get the sum of values in given range of the array.
    The following are parameters for this function.
 
    st    --> Pointer to segment tree
    index --> Index of current node in the segment tree. Initially 0 is
             passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment represented by
                 current node, i.e., st[index]
    qs & qe  --> Starting and ending indexes of query range */

int getSumUtil(int *st,int ss,int se,int qs,int qe,int index)
{
    if(qs<=ss && qe >= se)
    {
        return st[index];

    }

    if(se<qs||ss>qe)
    {
        return 0;
    }

    int mid = getMid(ss,se);
    return getSumUtil(st,ss,mid,qs,qe,2*index+1) + getSumUtil(st,mid+1,se,qs,qe,2*index+2);
}


void updateValueUtil(int *st,int ss,int se, int i, int diff, int index)
{
    if(i<ss||i>se)
        return;

    st[index] = st[index] + diff;
    if(se!=ss)
    {
        int mid = getMid(ss,se);
        updateValueUtil(st,ss,mid,i,diff,2*index + 1);
        updateValueUtil(st,mid+1,se,i,diff,2*index + 2);
    }
}


//function to update the value in input array and segment tree
//uses updateValueUtil to update the value in segment tree
void updateValue(int arr[],int *st,int n,int i,int new_val)
{
    if(i<0||i>n-1)
    {
        printf("invalid input");
        return -1;

    }

    int diff = new_val - arr[i];

    arr[i]=new_val;
    updateValueUtil(st,0,n-1,i,diff,0);
}

//return sum of elements between qs and qe
int getSum(int *st,int n,int qs,int qe)
{
    if(qs<0||qe>n-1||qs>qe)
    {
        printf("invalid input");
        return 1;
    }

    return getSumUtil(st,0,n-1,qs,qe,0);

}


//A recurcsive function which builds segemnt trees for array[ss....se]
// si is the current node in the segment tree st
int constructSTUtil(int arr[],int ss,int se,int *st,int si    )
{
    if(ss=se)
    {
        st[si]=arr[ss];
        return arr[ss];

        //if there are more than one element then recurr for left
        //and right subtrees and store their sum in this node
        int mid= getMid(ss,se);
        st[si] = constructSTUtil(arr,ss,mid,st,si*2+1) +  constructSTUtil(arr,mid+1,se,st,si*2+2);
        return st[si];
    }
}

//Function to construct segment tree. Allocates space for segement tree and calls constructSTUtil() to fill allocated memory.
int *constructST(int arr[],int n)
{
    int x= (int)ceil(log2(n)); //Height of tree
    int max_size = 2*(int)pow(2,x)-1;


    int *st =  (int *)malloc(max_size*sizeof(int));

    constructSTUtil(arr,0,n-1,st,0);

    return st;
}

int main()
{
    int arr[] = {1,3,5,7,9,11};
    int n = sizeof(arr)/sizeof(arr[0]);

    int *st=constructST(arr,n);

    printf("The sum of the range is %d",getSum(st,n,1,3));

    updateValue(arr,st,n,1,10);

    printf("The updated sum of range is %d",getSum(st,n,1,3));

    return 0;

}
