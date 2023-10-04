// Depth First Search (DFS Algorithm)

// TC - O(N) + O(2E) 
// N - No. of Nodes
// E - No. of Edges

// SC - O(3N)

#include<bits/stdc++.h>
using namespace std;


void dfs(int node, vector<int> adj[], int visited[], vector<int> &ls){

    // Step 2: Mark node as visited and add into dfs
    visited[node] = 1;
    ls.push_back(node);

    // Step 3: Traverse neighbours of a node and call dfs for unvisited node
    for(auto it: adj[node]){
        if(!visited[it]){
            dfs(it, adj, visited, ls);
        }
    }

}


int main(){
    int n,m;
    cin >> n >> m;
    
    int visited[n] = {0};
    vector<int> adj[n+1];

    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> DFS;
    
    // Step 1: Call dfs function for starting node 0
    dfs(0, adj, visited, DFS);

    for(auto it: DFS) cout << it << " ";

    return 0;
}