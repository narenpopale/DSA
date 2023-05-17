
// Searching in Binary Search Tree.
// Q. Target is given we have to return node if it is Present in BST or null otherwise.

// Tree Node

import java.lang.annotation.Target;

class Node {
    int data;
    Node left;
    Node right;

    Node(int val) {
        this.data = val;
        this.left = null;
        this.right = null;
    }
}

public class Search_In_BST {

    // Iterative Solution
    public static Node searchInBST(Node root, int Target) {

        while (root != null && root.data != Target) {
            root = Target < root.data ? root.left : root.right;
        }

        return root;
    }

    // Recursive Solution
    public static Node searchInBstRecursively(Node root, int Target) {

        if (root == null)
            return null;

        if (Target < root.data) {
            return searchInBstRecursively(root.left, Target);
        } else if (Target > root.data) {
            return searchInBstRecursively(root.right, Target);
        }

        return root;
    }

    public static void main(String[] args) {

    }

}
