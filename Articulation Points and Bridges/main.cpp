#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>

using namespace std;
typedef long long int ll;
typedef vector<ll> vll;

#define white 0
#define black 1
#define gray 2

vll arr[100];

vll dfs_visit;
vll dfs_parent;
vll dfs_low;
vll articulationVertex;

ll dfsNumberCounter,rootChildren,dfsRoot;
void APAB(ll u)
{
    ll i,v;
    dfs_low[u] = dfs_visit[u]=dfsNumberCounter++;
    for(i=0;i<arr[u].size();i++)
    {
        v = arr[u][i];
        if(dfs_visit[v]== white)                                 // a tree edge
        {
            dfs_parent[v] = u;
            if(u == dfsRoot)
            {
                rootChildren++;                                  // special case, count the children of the root
            }

            APAB(v);

            if(dfs_low[v] >= dfs_visit[u])                       // for articulation point
            {
                articulationVertex[u] = 1;
            }
            if (dfs_low[v] > dfs_visit[u])                       // for articulation bridge
            {
                cout<<"aticulation bridge"<<u<<' '<<v<<endl;
            }
            dfs_low[u] = min(dfs_low[u],dfs_low[v]);
        }
        else if (v != dfs_parent[u])                              // A back edge and not a direct cycle too
            dfs_low[u] = min(dfs_low[u],dfs_visit[v]);
    }
}

int main()
{

    arr[0].push_back(1);
    arr[1].push_back(0);
    arr[2].push_back(1);
    arr[1].push_back(2);
    arr[1].push_back(4);
    arr[4].push_back(1);
arr[1].push_back(3);
    arr[3].push_back(1);
    arr[1].push_back(5);
    arr[5].push_back(1);
    arr[5].push_back(4);
    arr[4].push_back(5);



    dfsNumberCounter= 0;
    dfs_visit.assign(6,white);
    dfs_parent.assign(6,0);
    dfs_low.assign(6,0);
    articulationVertex.assign(6,0);

    ll i;
    for(i=0;i<6;i++)
    {
        if(dfs_visit[i]==white)
        {
            dfsRoot = i;
            rootChildren = 0;
            APAB(i);
            articulationVertex[i] = (rootChildren>1);
        }
    }

    for(i=0;i<6;i++)
    {
        if(articulationVertex[i]== 1)
        {
            cout<<"vertex"<<i<<endl;
        }
    }
}
