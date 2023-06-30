
// You are given the root node of a binary search tree (BST) and a value to insert into the tree. 
// Return the root node of the BST after the insertion.


// TC - O(log N)
// SC - O(1)


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

public class Insert_Node_in_BST {

    public Node insertIntoBST(Node root, int val) {

        if (root == null) {
            return new Node(val);
        }

        Node node = root;

        while (true) {
            if (node.data <= val) {
                if (node.right != null) node = node.right;
                else {
                    node.right = new Node(val);
                    break;
                }
            } else {
                if (node.left != null) node = node.left;
                else {
                    node.left = new Node(val);
                    break;
                }
            }
        }

        return root;
    }

}
