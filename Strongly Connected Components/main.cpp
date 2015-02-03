#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <map>

using namespace std;
typedef long long int ll;
typedef vector<ll> vll;

#define white 0
#define black 1
#define gray 2


vll arr[100];
vll dfs_visit;
vll dfs_low;

vll S;
vll visited;

ll numSCC,dfsNumberCounter;

void SCC(ll u)
{

    //cout<<"SCC called at"<<u<<endl;
    ll j,v,k;
    dfs_low[u] = dfs_visit[u] = dfsNumberCounter++;
    S.push_back(u);                                    //stores u in a vector in order of visitation
    visited[u] = 1;

    for(j=0;j<arr[u].size();j++)
    {
        v = arr[u][j];

        if(dfs_visit[v] == white)                           //this check is neccessary otherwise when we have a back edge it calls SCC(i) where i node has
        {                                                   //already been visited
            //cout<<"dfs_visit is white at"<<v<<endl;
            SCC(v);
        }

        //cout<<"dfs_visit is white at"<<v<<endl;

        if (visited[u])
        {
            dfs_low[u] = min(dfs_low[u],dfs_low[v]);
        }



    }

    if(dfs_low[u] == dfs_visit[u])
    {
      //  cout<<"u is "<<u<<endl;
        ++numSCC;
        cout<<"SCC"<<numSCC<<endl;
        while(1)
        {
            k = S.back();
            S.pop_back();
            visited[k] = 0;
            cout<<k<<' ';
            if(u==k)
            {
                break;
            }


        }
        cout<<endl;
    }
}

int main()
{

    arr[0].push_back(1);
    arr[1].push_back(3);
    arr[3].push_back(2);
    arr[2].push_back(1);

    dfs_visit.assign(4,white);
    dfs_low.assign(4,0);
    visited.assign(4,0);
    dfsNumberCounter = numSCC = 0;

    ll i;

    for(i=0;i<4;i++)
    {
        if (dfs_visit[i]==white)
        {
            SCC(i);
        }
    }



}
