#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;

#define INF 1000000000


vll dist(5,INF);

vpll AdjList[1000];

int main()
{
   dist[s]=0;
   priority_queue<pll , vector<pll> , greater<pll> > pq;
   pq.push(pll(0,s));

   while(!pq.empty())
   {
       pll front = pq.top();
       pq.pop();
       ll d = front.first;
       ll u = front.second;
       ll j;

       if(d==dist[u])
       {
           for(j=0;j<AdjList[u].size();j++)
           {
               pll v = AdjList[u][j];
               if(dist[u] + v.second < dist[v.first])
               {
                   dist[v.first]= dist[u] + v.second;
                   pq.push( pll(dist[v.first],v.first));
               }
           }
       }
   }
}
