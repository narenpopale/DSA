
// Given the root of a binary search tree, and an integer k.
// return the kth largest value (1-indexed) of all the values of the nodes in the tree.

// TC - O(N)
// SC - O(N)

// Tree Node
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

public class Kth_Largest_in_BST {

    Node kthlargest(Node root, int k[]) {

        if (root == null) return null;

        Node right = kthlargest(root.right, k);

        if (right != null) return right;

        k[0]--;
        if (k[0] == 0) return root;

        return kthlargest(root.left, k);
    }

}
