
// Traversals of Binary Tree - DFS/BFS
// DFS
// 1. Pre-Order Traversal (Root Left Right)
// 2. In-Order Traversal (Left Root Right)
// 3. Post-Order Traversal (Left Right Root)

// BFS
// 1. Level-Order Traversal (Level Wise)

import java.util.*;

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

class Traversals {

    // 1. Pre-Order Traversal
    public void preorder(Node node) {
        if (node == null)
            return;

        System.out.println(node.data);
        preorder(node.left);
        preorder(node.right);
    }

    // Iterative Pre-Order Traversal
    public List<Integer> iterative_preorder(Node node) {
        List<Integer> ans = new ArrayList<>();

        if (node == null)
            return ans;

        Stack<Node> stack = new Stack<Node>();

        stack.push(node);

        while (!stack.isEmpty()) {
            node = stack.pop();

            if (node.right != null)
                stack.push(node.right);
            if (node.left != null)
                stack.push(node.left);

            ans.add(node.data);
        }

        return ans;
    }

    // 2. In-Order Traversal
    public void inorder(Node node) {
        if (node == null)
            return;

        inorder(node.left);
        System.out.println(node.data);
        inorder(node.right);
    }

    // Iterative In-Order Traversal
    public List<Integer> iterative_inorder(Node root) {
        List<Integer> ans = new ArrayList<>();

        Stack<Node> stack = new Stack<Node>();

        Node node = root;

        while (true) {
            if (node != null) {
                stack.push(node);
                node = node.left;
            } else {
                if (stack.isEmpty())
                    break;

                node = stack.peek();
                stack.pop();
                ans.add(node.data);
                node = node.right;
            }
        }

        return ans;
    }

    // 3. Post-Order Traversal
    public void postorder(Node node) {
        if (node == null)
            return;

        postorder(node.left);
        postorder(node.right);
        System.out.println(node.data);
    }

    // Iterative Post-Order Traversal - Using 2 Stacks
    public List<Integer> iterative_postorder(Node root) {
        List<Integer> ans = new ArrayList<Integer>();

        if (root == null)
            return ans;

        Stack<Node> st1 = new Stack<Node>();
        Stack<Node> st2 = new Stack<Node>();

        st1.push(root);

        while (!st1.isEmpty()) {
            Node node = st1.peek();
            st1.pop();
            st2.push(node);
            if (node.left != null)
                st1.push(node.left);
            if (node.right != null)
                st1.push(node.right);
        }

        while (!st2.isEmpty()) {
            Node node = st2.peek();
            ans.add(node.data);
            st2.pop();
        }

        return ans;
    }

    // Iterative Post-Order Traversal - Using 1 Stack
    public List<Integer> iterative_postorder_using_one_stack(Node root) {
        List<Integer> ans = new ArrayList<Integer>();

        if (root == null)
            return ans;

        Stack<Node> st = new Stack<Node>();
        Node curr = root;

        while (curr != null || !st.isEmpty()) {
            if (curr != null) {
                st.push(curr);
                curr = curr.left;
            } else {
                Node temp = st.peek().right;

                if (temp == null) {
                    temp = st.peek();
                    st.pop();
                    ans.add(temp.data);

                    while (!st.isEmpty() && temp == st.peek().right) {
                        temp = st.peek();
                        st.pop();
                        ans.add(temp.data);
                    }
                } else {
                    curr = temp;
                }
            }
        }

        return ans;
    }

    // 4. Level-Order Traversal
    public ArrayList<ArrayList<Integer>> levelorder(Node root) {

        // Answer Data Structure
        ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();

        if (root == null)
            return ans;

        // Queue Data Structure
        Queue<Node> queue = new LinkedList<Node>();
        queue.add(root);

        while (!queue.isEmpty()) {
            int size = queue.size();
            ArrayList<Integer> level = new ArrayList<Integer>();

            for (int i = 0; i < size; i++) {
                Node node = queue.peek();
                queue.remove();

                if (node.left != null)
                    queue.add(node.left);
                if (node.right != null)
                    queue.add(node.right);

                level.add(node.data);
            }

            ans.add(level);
        }

        return ans;
    }
}

public class Tree_Traversals {
    public static void main(String[] args) {

    }
}