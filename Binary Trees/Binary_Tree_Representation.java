
// Binary Tree Representation

// Tree Node
class Node {
    int data;
    Node left;
    Node right;

    Node(int val){
        this.data = val;
        this.left = null;
        this.right = null;
    }
}


public class Binary_Tree_Representation {
    public static void main(String[] args) {
        
        // Root Node                                         1
        Node root = new Node(1);

        // Root Node's Left and Right                        1
        root.left = new Node(2);//                     /   \             
        root.right = new Node(3);//                   2     3
        
        // Root Node's Left's Left and Right                 1
        root.left.left = new Node(4);//                /   \
        root.left.right = new Node(5);//              2     3
                                            //           / \
                                            //          4   5
        
        // Root Node's Right's Left and Right                 1
        root.right.left = new Node(6);//                /   \
        root.right.right = new Node(7);//              2     3
                                            //            / \   / \
                                            //           4   5 6   7
    }
}