// Given a binary tree, print the bottom view from left to right.
// A node is included in the bottom view if it can be seen when we look at the tree from the bottom.


// TC - O(N)
// SC - O(N)


#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node *left;
    Node *right;
};


vector<int> bottomView(Node *root)
{
    map<int, int> m;
    queue<pair<Node *, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {
        Node *temp = q.front().first;
        int val = q.front().second;
        q.pop();

        m[val] = temp->data;

        if (temp->left != NULL) q.push({temp->left, val - 1});
        if (temp->right != NULL) q.push({temp->right, val + 1});
    }

    vector<int> ans;

    for (auto i : m){
        ans.push_back(i.second);
    }
    
    return ans;
}