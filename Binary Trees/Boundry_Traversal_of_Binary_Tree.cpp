// Given a Binary Tree, find its Boundary Traversal.


// TC - O(H) + O(H) + O(N) ~ O(N)
// SC - O(N)


#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node *left;
    Node *right;
};


bool left(vector<int> &ans, Node *node) {
    if (node == NULL)
        return false;

    // Add the current node's data to the left boundary
    ans.push_back(node->data);

    // Traverse the left subtree while preferring left over right
    bool is = left(ans, node->left);
    if (is) return true;

    // If the left subtree doesn't exist or has been traversed, continue with the right subtree
    left(ans, node->right);

    return true;
}


bool right(vector<int> &ans, Node *node) {
    if (node == NULL) return false;

    // Traverse the right subtree while preferring right over left
    bool is = right(ans, node->right);

    // If the right subtree has been traversed, add the current node's data to the right boundary
    if (is) {
        ans.push_back(node->data);
        return true;
    }

    // If the right subtree doesn't exist or has been traversed, continue with the left subtree
    right(ans, node->left);

    // Add the current node's data to the right boundary
    ans.push_back(node->data);

    return true;
}


void leaf(vector<int> &ans, Node *node) {
    if (node == NULL) return;

    // Check if the current node is a leaf node (has no children)
    if (node->left == NULL && node->right == NULL) {
        // Add the data of leaf nodes to the leaf list
        ans.push_back(node->data);
    }

    // Recursively explore the left and right subtrees
    leaf(ans, node->left);
    leaf(ans, node->right);
}


vector<int> boundary(Node *root) {
    vector<int> ans;

    // Add the root node to the result
    ans.push_back(root->data);

    // Traverse the left boundary
    vector<int> l;
    left(l, root->left);
    for (auto i : l) ans.push_back(i);

    // Collect leaf nodes from the left and right subtrees, excluding the ones in the left or right boundary
    vector<int> first, second;
    leaf(first, root->left);
    leaf(second, root->right);

    // Remove the first element from 'first' (if it exists) as it's part of the left boundary
    if (first.size() > 0) first.erase(first.begin());

    // Remove the last element from 'second' (if it exists) as it's part of the right boundary
    if (second.size() > 0) second.pop_back();

    // Add the remaining leaf nodes to the result
    for (auto i : first) ans.push_back(i);
    for (auto i : second) ans.push_back(i);

    // Traverse the right boundary
    vector<int> r;
    right(r, root->right);
    for (auto i : r) ans.push_back(i);

    return ans;
}