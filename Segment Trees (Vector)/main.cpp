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
typedef vector<vll> vvll;




ll getMid(ll start,ll end)
{
  return start + (end-start)/2;
}

vll numbers;
vll ST;



ll update(ll newVal, ll index,ll ss,ll se,ll node)
{
   if(index<ss || index >se) {return 0;}

   ST[node] = ST[node] + (newVal - numbers[index]);
   if(ss!=se)
   {
      ll mid  = getMid(ss,se);
   update(newVal,index,ss,mid,2*node+1);
   update(newVal,index,mid+1,se,2*node+2);

   }
}

ll getSum(ll ss,ll se,ll qs,ll qe,ll index)
{
    if((ss>=qs) && (se<=qe)) {  return ST[index];}

    if((ss>qe) || (qs>se) ) { return 0; }

    ll mid= getMid(ss,se);
    return getSum(ss,mid,qs,qe,index*2+1) + getSum(mid+1,se,qs,qe,index*2+2);

}

ll constructST(ll start,ll end,ll index)
{
   if(start==end)
   {
      ST[index] = numbers[start];
      return numbers[start];
   }
   ll mid = getMid(start,end);
   ll val = constructST(start,mid,2*index+1) + constructST(mid+1,end,index*2 + 2);
   ST[index] = val;
   return ST[index];
}


//To be used when in case of problems involving switching of states. When a segment of the array is either switched off or on
ll updateTree(ll start,ll end,ll qstart,ll qend,ll index,ll val)
{

    if ((start==end) && (qstart<=start && qend>=start))
    {
       if (ST[index] == 1 && val == 1) return 0;
       else if (ST[index] == 0 && val == 1) {ST[index] = 1; return 1;}
       else if (ST[index] == 1 && val == 0) {ST[index] = 0; return -1;}
       else if (ST[index] == 0 && val == 0) return 0;
    }

    ll mid = getMid(start,end);

    if(start>qend || end <qstart){return 0; }

    ll change = updateTree(start,mid,qstart,qend,2*index+1,val) + updateTree(mid+1,end,qstart,qend,2*index+2,val);
    ST[index] = ST[index] + change;
    return change;

}


ll printall(ll n)         // Prints the array after the updates
{
   ll i;
   for(i=0;i<n;i++)
   {
      cout<<getSum(0,n-1,i,i,0)<<' ';
   }
   cout<<endl;
}


int main()
{
   ll n;
   cout<<"Enter length of array"<<endl;
   cin>>n;

   ll i,temp,a,b,j,c;

   for(i=0;i<n;i++)
   {
      cin>>temp;
      numbers.push_back(temp);
   }


   //Constructing the Segment Tree
   ll x= (ll)ceil(log2(n)); //Height of tree
   ll max_size = 2*(ll)pow(2,x)-1;

   for(i=0;i<max_size;i++)
   {
      ST.push_back(0);
   }
   constructST(0,n-1,0);

   ll q;
   cout<<"enter number of segment updates"<<endl;
   cin>>q;
   cout<<"Enter updates in the form :start-end-new value:"<<endl;rsk
   for(i=0;i<q;i++)
   {
     cin>>a>>b>>c;
     updateTree(0,n-1,a,b,0,c);
    printall(n);


   }




}
