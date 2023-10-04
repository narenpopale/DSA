// Breadth First Search (BFS Algorithm)

// TC - O(N) + O(2E) 
// N - No. of Nodes
// E - No. of Edges

// SC - O(3N)

#include<bits/stdc++.h>
using namespace std;


vector<int> bfs(int V,vector<int> adj[]){

    // BFS Traversal
    vector<int> bfs;

    // Visited Array
    int visited[V] = {0};

    // Queue
    queue<int> q;

    // Step 1: Put first node into the queue and mark visited
    q.push(0);
    visited[0] = 1;

    while (!q.empty())
    {
        // Step 2: Take first node from queue and pop it 
        int node = q.front();
        q.pop();

        bfs.push_back(node);

        // Step 3: Add all the neighbour nodes of node into the queue and Mark visited
        for(auto it: adj[node]){
            if(!visited[it]){
                visited[it] = 1;
                q.push(it);
            }
        }
    }
    
    return bfs;
}


int main(){
    int n,m;
    cin >> n >> m;
    
    vector<int> adj[n+1];

    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> BFS = bfs(n, adj);

    for(auto it: BFS) cout << it << " ";

    return 0;
}