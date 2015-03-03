#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <list>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <limits.h>
#include <climits>
#include <set>

using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;

vvpll adjList;

vll owner,visited;

ll alternatingPath(ll left)
{

   if(visited[left]==1)
   {
     return 0;

   }

   visited[left]  = 1;

   ll j,i;
   for(j=0;j<(ll)adjList[left].size();j++)
   {

      //for the current node left on the left side we iterate through all the nodes on the right side
      // that is connected to. Each connection is in the form of a pair.
      pll right = adjList[left][j];

      // if the node on right (given by right->first) has no owner implying that it has not been matched yet
      // OR check if the node on the right forms an augmenting Path
      if(owner[right.first]==-1 || alternatingPath(owner[right.first]))
      {
          owner[right.first] = left;
          return 1;
      }
   }

   return 0;


}

int main()
{
   // Forming the bipartitte graph
   ll V = 4;              // Number of vertices in the graph
   ll left_vertices = 2;   // Number of vertices of left side set
   ll cardinality = 0;
   ll i;
   vpll temp;
   for(i=0;i<V;i++)
   {
      adjList.push_back(temp);
   }

   adjList[0].push_back(pll(1,1));
   adjList[0].push_back(pll(3,1));
   adjList[2].push_back(pll(3,1));

   vll leftVertices;               // list of vertices in left set
   leftVertices.push_back(0);
   leftVertices.push_back(2);



   owner.assign(4,-1);

   ll left = 0;

   for(left =0;left<left_vertices;left++)
   {
      visited.assign(left_vertices,0);         // reset before every iteration
      for(i=0;i<left_vertices;i++)
      {
         visited[leftVertices[i]]=0;
      }


      cardinality += alternatingPath(leftVertices[left]);           // Visiting all the vertices in the left set
      cout<<"left is"<<leftVertices[left]<<endl;
      cout<<"cardinality is"<<cardinality<<endl;

   }

   cout<<"cardinality is "<<cardinality<<endl;

}
