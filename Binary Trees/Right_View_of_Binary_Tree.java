
// Given the root of a binary tree, imagine yourself standing on the right side of it, 
// return the values of the nodes you can see ordered from top to bottom.


import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;


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


public class Right_View_of_Binary_Tree {
    
    // 1st Approach - Level Order Traversal
    // TC - O(N)
    // SC - O(N)
    
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<Integer>();
        Queue<TreeNode> queue = new LinkedList<>();
        
        if(root == null) return ans;
        
        queue.add(root);

        while(!queue.isEmpty()) {
            int size = queue.size();

            for(int i = 0;i < size; i++) {
                if(i == size - 1) ans.add(queue.peek().data);
                if(queue.peek().left != null) queue.add(queue.peek().left);
                if(queue.peek().right != null) queue.add(queue.peek().right);
                queue.remove();
            }
        }
        
        return ans;
    }
    
    
    // 2nd Approach - Optimal
    // TC - O(N)
    // SC - O(H)

    public List<Integer> rightsideView(TreeNode root) {
        List<Integer> result = new ArrayList<Integer>();
        rightView(root, result, 0);
        return result;
    }
    
    public void rightView(TreeNode curr, List<Integer> result, int currDepth){
        if(curr == null){
            return;
        }
        if(currDepth == result.size()){
            result.add(curr.data);
        }
        
        rightView(curr.right, result, currDepth + 1);
        rightView(curr.left, result, currDepth + 1);
        
    }

}
