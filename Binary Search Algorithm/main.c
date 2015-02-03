#include <stdio.h>
#include <stdlib.h>
int binSearch(int arr[],int n,int x)
{
    int start = 0;
    int end = n-1;
    int mid = 0;

    while(start<=end)
    {
        mid=(start+end)/2;
        if(arr[mid]==x)
        {
            return mid;
        }

        else if (arr[mid]>x)
        {
            end = mid-1;
        }
        else
        {
            start= mid+1;
        }
    }

}


int main()
{
    int arr[] = {1,3,6,8,9,13,26};

    int x = binSearch(arr,7,23);

    printf("%d",x);
}
