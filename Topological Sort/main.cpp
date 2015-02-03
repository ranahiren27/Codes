#include <iostream>
#include <vector>
#include <list>
#include <limits.h>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef vector<ll> vll;

#define white 1
#define black 0
#define gray 2

vll arr[100];

vll topSort;
vll dfs_visit;

void dfs2(ll u)
{
    ll i,j;
    dfs_visit[u] = black;
    for(i=0;i<arr[u].size();i++)
    {
        j = arr[u][i];
        if( dfs_visit[j] == 1)
        {
            dfs2(j);
        }
    }
    topSort.push_back(u);
}

int main()
{

    ll i,j;
    ll nCC=0;


    arr[0].push_back(1);
    arr[0].push_back(2);
    arr[1].push_back(2);
    arr[1].push_back(3);
    arr[2].push_back(3);
    arr[2].push_back(5);
    arr[3].push_back(4);
    arr[7].push_back(6);

    dfs_visit.assign(8,1);

    for(i=0;i<8;i++)
    {
        if(dfs_visit[i]== white)
        {
            nCC++;
            dfs2(i);
        }
    }

    reverse(topSort.begin(),topSort.end());

    for(i=0;i<topSort.size();i++)
    {
        cout<<topSort[i]<<' ';
    }


}
