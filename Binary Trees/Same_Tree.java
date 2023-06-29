
// Given two Binary Tree. Write a program to check if two trees are identical or not.

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

public class Same_Tree {

    static boolean isIdentical(Node node1, Node node2) {
        
        if (node1 == null && node2 == null) return true;
        if (node1 == null || node2 == null) return false;

        return ((node1.data == node2.data) && isIdentical(node1.left, node2.left)
                && isIdentical(node1.right, node2.right));
    }

    public static void main(String args[]) {

        Node root1 = new Node(1);
        root1.left = new Node(2);
        root1.right = new Node(3);
        root1.right.left = new Node(4);
        root1.right.right = new Node(5);

        Node root2 = new Node(1);
        root2.left = new Node(2);
        root2.right = new Node(3);
        root2.right.left = new Node(4);

        if (isIdentical(root1, root2)){
            System.out.println("Two Trees are identical");
        }
        else{
            System.out.println("Two trees are non-identical");
        }

    }
}
