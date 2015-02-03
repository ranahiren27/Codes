#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
typedef map<ll,ll> mll;

#define white 0
#define black 1
#define gray 2
vll arr[100];

vll dfs_visit;

vll dfs_parent;


void graphCheck(ll u)
{
    ll i,v;
    dfs_visit[u] = gray;                       //node visisted but not completed
    for(i=0;i<arr[u].size();i++)
    {
        v = arr[u][i];
        if(dfs_visit[v]== white)
        {
            dfs_parent[v] = u;
            graphCheck(v);
        }
        else if (dfs_visit[v] == gray)       // gray node to gray node
        {
            if (v == dfs_parent[u])          // bi-directional edge
            {
                cout<<"Bidirectional"<<u<<' '<<v<<endl;
            }
            else                              // back edge , shows that there is a cycle
            {
                cout<<"back edge"<<u<<' '<<v<<endl;
            }
        }
        else if (dfs_visit[v] == black)
        {
            cout<<"forward/cross edge"<<u<<' '<<v<<endl;
        }
    }

    dfs_visit[u] = black;

}

int main()
{
    arr[0].push_back(1);
    arr[1].push_back(0);
    arr[2].push_back(1);
    arr[1].push_back(2);
    arr[1].push_back(3);
    arr[3].push_back(1);

    arr[2].push_back(3);
    arr[3].push_back(2);
    arr[3].push_back(4);
    arr[4].push_back(3);
    arr[7].push_back(6);
    arr[6].push_back(7);
    arr[8].push_back(6);
    arr[6].push_back(8);

    dfs_visit.assign(9,white);
    dfs_parent.assign(9,0);

    ll i,numComp = 0;
    for(i=0;i<9;i++)
    {
        if(dfs_visit[i]== white)
        {
            numComp++;
            cout<<"Component"<<numComp<<' ';
            graphCheck(i);
        }
    }

}
