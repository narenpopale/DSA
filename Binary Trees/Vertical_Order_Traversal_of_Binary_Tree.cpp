// Write a program for Vertical Order Traversal of a Binary Tree.


// TC - O(N * logN)
// SC - O(N)


#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node *left;
    Node *right;
};


vector<vector<int>> findVertical(Node *root)
{

    map<int, map<int, multiset<int>>> Nodes;
    queue<pair<Node*, pair<int, int>>> todo;

    todo.push({root, {0, 0}}); // initial vertical and level

    while (!todo.empty())
    {
        Node *temp = todo.front().first;
        // x -> vertical , y->level
        int x = todo.front().second.first, y = todo.front().second.second;

        todo.pop();

        Nodes[x][y].insert(temp->data); // inserting to multiset

        if (temp->left != NULL)
        {
            todo.push({temp->left, {x - 1, y + 1}});
        }
        if (temp->right != NULL)
        {
            todo.push({temp->right, {x + 1, y + 1}});
        }

    }

    vector<vector<int>> ans;

    for (auto p : Nodes)
    {
        vector<int> col;
        
        for (auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }

        ans.push_back(col);
    }

    return ans;
}