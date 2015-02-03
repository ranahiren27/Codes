#include <stdio.h>
#include <stdlib.h>


void swap(int ar[],int a,int b)
{
    int temp;
    temp = ar[a];
    ar[a]= ar[b];
    ar[b] = temp;
}


int part(int ar[],int start, int end)
{

    int i,temp;
    int pivot = ar[end];
    int pIndex = start;

    for(i=start;i<end;i++)
    {
        if(ar[i]<=pivot)
        {
            swap(ar,i,pIndex);
            pIndex++;
        }


    }

    swap(ar,end,pIndex);

    return pIndex;


}
void quickSort(int ar[],int start, int end)
{

    if(start<end)
    {
        int index = part(ar,start,end);
        quickSort(ar,start,index-1);
        quickSort(ar,index+1,end);
    }

}

int main()
{
    int n;
    scanf("%d",&n);

    int a[n];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }

//its n-1 and not n
    quickSort(a,0,n-1);

    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);

    }
}
