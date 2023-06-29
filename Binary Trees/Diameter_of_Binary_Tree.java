
// Find the Diameter of a Binary Tree. 
// Diameter is the length of the longest path between any 2 nodes in the tree and this path may or may not pass from the root.

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

public class Diameter_of_Binary_Tree {
    public int diameterOfBinaryTree(TreeNode root) {
        int[] diameter = new int[1];

        height(root, diameter);

        return diameter[0];
    }

    private int height(TreeNode node, int[] diameter) {

        if (node == null) {
            return 0;
        }

        int lh = height(node.left, diameter);
        int rh = height(node.right, diameter);

        diameter[0] = Math.max(diameter[0], lh + rh);
        
        return 1 + Math.max(lh, rh);
    }
}
