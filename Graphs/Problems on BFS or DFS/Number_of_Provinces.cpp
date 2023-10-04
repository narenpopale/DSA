// Given an undirected graph with V vertices.
// We say two vertices u and v belong to a single province if there is a path from u to v or v to u.
// Your task is to find the number of provinces.


// TC - O(N) + O(N+2E)
// N - No. of Nodes
// E - No. of Edges

// SC - O(N) + O(N)


#include <bits/stdc++.h>
using namespace std;

// dfs traversal function
void dfs(int node, vector<int> adjLs[], int vis[])
{
    // mark the more as visited
    vis[node] = 1;

    for (auto it : adjLs[node])
    {
        if (!vis[it])
        {
            dfs(it, adjLs, vis);
        }
    }
}

int numProvinces(vector<vector<int>> adj, int V)
{
    vector<int> adjLs[V];

    // to change adjacency matrix to list
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            // self nodes are not considered
            if (adj[i][j] == 1 && i != j)
            {
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }


    int vis[V] = {0};
    int cnt = 0;


    for (int i = 0; i < V; i++)
    {
        // if the node is not visited
        if (!vis[i])
        {
            // counter to count the number of provinces
            cnt++;
            dfs(i, adjLs, vis);
        }
    }

    return cnt;
}

int main()
{

    vector<vector<int>> adj{
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}};

    cout << numProvinces(adj, 3) << endl;

    return 0;
}