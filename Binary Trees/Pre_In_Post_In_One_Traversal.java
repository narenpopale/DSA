
// Pre-Order, In-Order and Post-Order Traversals in One Traversal
// Using 1 stack
// T.C. - O(N) N - No. of Nodes
// S.C. - O(N)

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

// Pair class 
class Pair {
    Node node;
    int num;

    Pair(Node node, int num){
        this.node = node;
        this.num = num;
    }
}

public class Pre_In_Post_In_One_Traversal { 

    public static void preInPostTraversal(Node root, List < Integer > pre, List < Integer > in , List < Integer > post){    
        Stack<Pair> stack = new Stack<Pair>();
    
        stack.push(new Pair(root, 1));
    
        if(root == null) return;
    
        while(!stack.isEmpty()){
    
            Pair node = stack.peek();
            stack.pop();
            
            // this is part of pre
            // increment 1 to 2 
            // push the left side of the tree
            if(node.num == 1){
                pre.add(node.node.data);
                node.num++;
                stack.push(node);
    
                if(node.node.left != null){
                    stack.push(new Pair(node.node.left, 1));
                }
            }
            
            // this is a part of in 
            // increment 2 to 3 
            // push right
            else if(node.num == 2){
                in.add(node.node.data);
                node.num++;
                stack.push(node);
    
                if(node.node.right != null){
                    stack.push(new Pair(node.node.right, 1));
                }                
            }
            // don't push it back again 
            else {
                post.add(node.node.data);
            }
        }
    }

    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right = new Node(3);
        root.right.left = new Node(6);
        root.right.right = new Node(7);

        List < Integer > pre = new ArrayList < > ();
        List < Integer > in = new ArrayList < > ();
        List < Integer > post = new ArrayList < > ();
        preInPostTraversal(root, pre, in , post);

        System.out.println("The preorder Traversal is : ");
        for (int nodeVal: pre) {
            System.out.print(nodeVal + " ");
        }
        System.out.println();
        System.out.println("The inorder Traversal is : ");
        for (int nodeVal: in ) {
            System.out.print(nodeVal + " ");
        }
        System.out.println();
        System.out.println("The postorder Traversal is : ");
        for (int nodeVal: post) {
            System.out.print(nodeVal + " ");
        }
        System.out.println();
    }

}
