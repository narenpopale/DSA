
// Given the root of a binary tree, return the maximum width of the given tree.
// The maximum width of a tree is the maximum width among all levels.
// The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes)


// TC - O(N)
// SC - O(N)


import java.util.*;

class TreeNode {
    int data;
    TreeNode left, right;

    TreeNode(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

class Pair {
    TreeNode node;
    int num;

    Pair(TreeNode _node, int _num) {
        num = _num;
        node = _node;
    }
}


public class Maximum_Width_of_Binary_Tree {

    public static int widthOfBinaryTree(TreeNode root) {
        if (root == null) return 0;

        int ans = 0;
        Queue<Pair> q = new LinkedList<>();

        q.offer(new Pair(root, 0));
        
        while (!q.isEmpty()) {

            int size = q.size();
            int mmin = q.peek().num; // to make the id starting from zero
            int first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                int cur_id = q.peek().num - mmin;
                TreeNode node = q.peek().node;

                q.poll();

                if (i == 0) first = cur_id;
                if (i == size - 1) last = cur_id;
                if (node.left != null) q.offer(new Pair(node.left, cur_id * 2 + 1));
                if (node.right != null) q.offer(new Pair(node.right, cur_id * 2 + 2));
            }

            ans = Math.max(ans, last - first + 1);
        }
        
        return ans;
    }

}
