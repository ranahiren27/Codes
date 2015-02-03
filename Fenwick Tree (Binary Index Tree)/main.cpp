#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;
typedef long long int ll;
typedef vector<ll> vll;

#define LSOne(s) (s & (-s))

void ft_create(vll &t,ll n)
{
    t.assign(n+1,0);
}

ll ft_rsq(vll &t,ll b)                       //returns RSQ[1,b]
{
    ll sum = 0;
    for(;b;b -= LSOne(b))
    {
        sum+= t[b];
    }

    return sum;
}

ll ft_rsq(vll &t,ll a, ll b)
{
    return ft_rsq(t,b) - (a==1?0:ft_rsq(t,a));
}

ll ft_rsq2(vll &t,ll a, ll b)
{
    return (ft_rsq(t,b) - ft_rsq(t,a));
}

void ft_adjust(vll &t,ll k ,ll v)                   //add/subtract value v from the kth count
{
    for(;k<=(ll)t.size();k += LSOne(k))
    {
        t[k]+=v;
    }
}





int main()
{
    vll ft;
    ft_create(ft,6);
    ft_adjust(ft,1,4);

    ft_adjust(ft,2,6);
    ft_adjust(ft,3,2);
    ft_adjust(ft,4,8);
    ft_adjust(ft,5,5);
    ft_adjust(ft,6,2);
ll i;

for(i=1;i<=5-1;i++)
{
    cout<<i<<' '<<ft_rsq(ft,i,i+1)<<endl;
}
cout<<ft_rsq(ft,1,1)<<endl;
cout<<ft_rsq(ft,2)<<endl;
cout<<ft_rsq2(ft,1,2);

}
