// Graph Representation - 2 Ways

// A) Undirected Graph
// 1. Adjacency Matrix - SC - O(n * n) n = no. of nodes
// 2. Adjacency List   - SC - O(2 * No. of Edges)

// B) Directed Graph
// 1. Adjacency Matrix - SC - O(n * n) n = no. of nodes
// 2. Adjacency List   - SC - O(No. of Edges)

#include<iostream>
#include<vector>
using namespace std;

int main(){
    // n = No. of Nodes 
    // m = No. of Edges
    int n,m;
    cin >> n >> m;
    
    // A) Undirected Graph

    // 1. Adjacency Matrix
    int adj[n+1][n+1];

    for (int i = 0; i < m; i++)
    {
        // u,v = Representation of edge between 2 nodes u and v
        int u,v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    // 2. Adjacency List
    vector<int> adj[n+1];

    for (int i = 0; i < m; i++)
    {
        // u,v = Representation of edge between 2 nodes u and v
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // B) Directed Graph

    // 1. Adjacency Matrix
    int adj[n+1][n+1];

    for (int i = 0; i < m; i++)
    {
        // u,v = Representation of edge between 2 nodes u and v
        int u,v;
        cin >> u >> v;
        adj[u][v] = 1;
    }
    
    // 2. Adjacency List
    vector<int> adj[n+1];

    for (int i = 0; i < m; i++)
    {
        // u,v = Representation of edge between 2 nodes u and v
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }


    return 0;
}