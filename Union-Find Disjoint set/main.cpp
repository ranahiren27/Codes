#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;
typedef long long int ll;
typedef vector<ll> vll;

vll pset;

void initSet(ll n)
{
    pset.assign(n,0);
    for(i=0;i<n;i++)
    {
        pset[i]=i;
    }
}

ll findSet(ll i)
{
    return (pset[i]==i)? i : (pset[i] = findSet(pset[i]));
}

bool isSameSet(ll i,ll j)
{
    return findSet(i)==findSet(j);
}

void unionSet(ll i, ll j)
{
    pset[findSet(i)] = findSet(j);
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
