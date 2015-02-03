#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <list>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <limits.h>
#include <climits>
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;


void quickSort( ll[], ll,ll,ll);
ll partition( ll[], ll, ll,ll);


int main()
{

    ll n,i,temp;
    cin>>n;


	ll a[5001];
	for(i=0;i<n;i++)
	{
	  cin>>temp;
	  a[i] = temp;
	}

	quickSort( a, 0, n-1,n);






}



void quickSort( ll a[], ll l, ll r,ll n)
{
   int j,i;

   if( l < r )
   {
   	// divide and conquer
        j = partition( a, l, r,n);
       for(i=0;i<n;i++)
       {
         cout<<a[i]<<' ';
       }
       cout<<endl;

       quickSort( a, l, j-1,n);
       quickSort( a, j+1, r,n);


   }

}



ll partition( ll a[], ll l, ll r,ll n) {

   //cout<<"l and r are"<<l<<' '<<r<<endl;
   ll pivot = a[r];
   ll smallIndex = l;

   ll temp,i,j;

   for(i=l;i<r;i++)
   {
     if(a[i]<pivot)
     {

       if(smallIndex == i)
       {
         smallIndex++;
       }
       else
       {
         temp = a[smallIndex];
         a[smallIndex] = a[i];
         a[i] = temp;
         smallIndex++;
       }

     }


     //for(j=0;j<n;j++)
      // {
      //   cout<<a[j]<<' ';
     //  }
      // cout<<endl;

   }

   temp = a[smallIndex];
         a[smallIndex] = a[r];
         a[r] = temp;

   // cout<<"smallindex is"<<smallIndex<<endl;

   return smallIndex;

}







