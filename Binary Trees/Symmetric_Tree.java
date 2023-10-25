// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).


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

public class Symmetric_Tree {
    
    boolean solve(TreeNode node1, TreeNode node2) {
        if(node1 == null && node2 == null) return true;
        if(node1 == null || node2 == null) return false;
        if(node1.data != node2.data) return false;

        boolean n1 = solve(node1.left, node2.right);
        boolean n2 = solve(node1.right, node2.left);

        return n1 && n2;
    }

    public boolean isSymmetric(TreeNode root) {
        return solve(root, root);
    }

}
