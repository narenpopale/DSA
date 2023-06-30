
// Given the root of a binary search tree, and an integer k.
// return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

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

public class Kth_Smallest_in_BST {

    Node kthsmallest(Node root, int k[]) {

        if (root == null)
            return null;

        Node left = kthsmallest(root.left, k);

        if (left != null)
            return left;

        k[0]--;
        if (k[0] == 0)
            return root;

        return kthsmallest(root.right, k);
    }

}
