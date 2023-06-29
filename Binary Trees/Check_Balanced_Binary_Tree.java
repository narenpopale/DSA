
// Check whether the given Binary Tree is a Balanced Binary Tree or not. 
// A binary tree is balanced if, for all nodes in the tree, the difference between left and right subtree height is not more than 1.

// TC - O(N)
// SC - O(1)


// Tree Node
class TreeNode {
    int data;
    TreeNode left;
    TreeNode right;

    TreeNode(int val) {
        this.data = val;
        this.left = null;
        this.right = null;
    }
}

public class Check_Balanced_Binary_Tree {
    
    public boolean isBalanced(TreeNode root) {
        return dfsHeight (root) != -1;
    }

    int dfsHeight (TreeNode root) {
        if (root == null) return 0;
        
        int leftHeight = dfsHeight (root.left);
        if (leftHeight == -1) return -1;
        int rightHeight = dfsHeight (root.right);
        if (rightHeight == -1) return -1;
        
        if (Math.abs(leftHeight - rightHeight) > 1)  return -1;
        return Math.max(leftHeight, rightHeight) + 1;
    }

}
