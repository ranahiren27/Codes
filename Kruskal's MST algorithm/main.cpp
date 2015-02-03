#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;



vll pset;

void initSet(ll n)
{
    ll i;
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
    ll E;               //No of edges
    cin>>E;
    ll V;                //no of nodes
    cin>>V;
    vector< pair<ll,pll> > EdgeList;
    ll i,a,b,weight;
    for(i=0;i<E;i++)
    {
        cin>>a>>b>>weight;
        EdgeList.push_back(make_pair(weight,pll(a,b)));

    }

    sort(EdgeList.begin(),EdgeList.end());


    ll mstCost = 0;
    initSet(V);

    for(i=0;i<E;i++)
    {
        pair<int, pll> front = EdgeList[i];
        if(!isSameSet(front.second.first,front.second.second))
        {
            mstCost+=front.first;
            unionSet(front.second.first,front.second.second);
        }
    }

    cout<<"MST cost is "<<mstCost<<endl;

}
