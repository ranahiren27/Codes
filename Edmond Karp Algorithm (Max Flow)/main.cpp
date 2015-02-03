#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <string.h>
#include <list>
#include <stdlib.h>
#include <ctime>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <stack>
#include <queue>
#include <limits.h>

using namespace std;
typedef long long int ll;

#define V 6


ll BFS(ll rGraph[V][V],ll s, ll t, ll parent[])
{
    ll i;
    ll *visited = new ll[V+1];
    for(i=0;i<V;i++)
    {
        visited[i] = 0;
    }

    queue<ll>  q;
    q.push(s);
    visited[s] = 1;
    parent[s] = -1;


    while(!q.empty())
    {
        ll u = q.front();
        q.pop();

        for(i=0;i<V;i++)
        {
            if (visited[i]==0 && rGraph[u][i]>0)
            {
                q.push(i);
                parent[i] = u;
                visited[i] = 1;
            }
        }
    }

    if (visited[t] == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }



}

ll fordFulkerson(ll graph[V][V],int s,int t)
{
    ll u,v;

    ll rGraph[V][V];
    for(u=0;u<V;u++)
    {
        for(v=0;v<V;v++)
        {
            rGraph[u][v] = graph[u][v];
        }
    }

    ll parent[V];

    ll max_flow = 0;

    while( BFS(rGraph,s,t,parent) == 1 )
    {
        int path_flow = INT_MAX;
        for(v = t;v!=s;v = parent[v])
        {
            u = parent[v];
            if(rGraph[u][v] <path_flow)
            {
                path_flow = rGraph[u][v];
            }

        }

        for(v = t;v!=s;v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;

    }

    return max_flow;




}

int main()
{
    ll graph[V][V] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };

     cout<<"The max flow is"<< fordFulkerson(graph,3,5);
}
