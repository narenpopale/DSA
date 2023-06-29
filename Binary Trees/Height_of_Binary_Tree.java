
// Find the Maximum Depth of Binary Tree. 
// Maximum Depth is the count of nodes of the longest path from the root node to the leaf node.

import java.util.*;

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

public class Height_of_Binary_Tree {

    // Solution 1 : Level Order Traversal
    // TC - O(n)
    // SC - O(n)
    private static int levelOrder(TreeNode root) {
        if (root == null) {
            return 0;
        }

        LinkedList<TreeNode> queue = new LinkedList<>();
        queue.addLast(root);

        int level = 0;

        while (queue.size() > 0) {
            int size = queue.size();

            while (size-- > 0) {
                TreeNode remNode = queue.removeFirst();
                if (remNode.left != null) {
                    queue.addLast(remNode.left);
                }
                if (remNode.right != null) {
                    queue.addLast(remNode.right);
                }
            }

            level++;
        }

        return level;
    }


    // Solution 2 : Post Order Traversal
    // TC - O(n)
    // SC - O(1)
    public int maxDepth(TreeNode root) {
        if (root == null)
            return 0;

        int lh = maxDepth(root.left);
        int rh = maxDepth(root.right);

        return 1 + Math.max(lh, rh);
    }

}
