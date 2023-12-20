// We are given a binary tree T and a Node V. We need to print a path from the root of the tree to the Node.


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


bool getPath(Node *root, vector<int> &arr, int x)
{
    // if root is NULL
    // there is no path
    if (!root) return false;

    // push the Node's value in 'arr'
    arr.push_back(root->data);

    // if it is the required Node
    // return true
    if (root->data == x) return true;

    // else check whether the required Node lies
    // in the left subtree or right subtree of
    // the current Node
    if (getPath(root->left, arr, x) || getPath(root->right, arr, x)) return true;

    // required Node does not lie either in the
    // left or right subtree of the current Node
    // Thus, remove current Node's value from
    // 'arr'and then return false
    arr.pop_back();

    return false;
}


int main() {
    Node *root;
    int node = 3;

    vector<int> ans;

    getPath(root, ans, node);

    return 0;
}