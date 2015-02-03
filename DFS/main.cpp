#include <iostream>
#include <stack>

using namespace std;
typedef long long int ll;
typedef stack<ll> ST;
class Graph {
    private:
        int n;
        int **A;
    public:
        Graph(int size = 2);
        ~Graph();
        bool isConnected(int, int);
        void addEdge(int x, int y);
        int DFS(int x,  int y);
};

Graph::Graph(int size) {
    int i, j;
    if (size < 2) n = 2;
    else n = size;
    A = new int*[n];
    for (i = 0; i < n; ++i)
        A[i] = new int[n];
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            A[i][j] = 0;
}

Graph::~Graph() {
    for (int i = 0; i < n; ++i)
    delete [] A[i];
    delete [] A;
}

bool Graph::isConnected(int x, int y) {
    return (A[x-1][y-1] == 1);
}

void Graph::addEdge(int x, int y) {
    A[x-1][y-1] = A[y-1][x-1] = 1;
}

int Graph::DFS(int x, int required){
     ST s;
    bool *visited = new bool[n+1];
    int i;
    for(i = 0; i <= n; i++)
        visited[i] = false;
    s.push(x);
    visited[x] = true;
    if(x == required) return 1;
    cout << "Depth first Search starting from vertex ";
    cout << x << " : " << endl;
    while(!s.empty())
    {
        ll k = s.top();
        s.pop();
        if(k == required)
        {

          return 1;
        }
        cout<<k<<" ";
        for (i = n; i >= 0 ; --i)
            if (isConnected(k, i) && !visited[i]) {
                s.push(i);
                visited[i] = true;
            }
    }
    cout<<endl;
    delete [] visited;
    return 0;
}

int main()
{
    Graph g = Graph(5);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,5);
    ll a = g.DFS(2,5);
    cout<<endl;
    cout<<a<<endl;
}
