
// Given a BST and a number X, find Ceil of X.
// Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.


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

public class Ceil_in_BST {
    
    int findCeil(Node root, int x) {

        int ans = -1;
        Node node = root;
        
        while(node != null){
            
            if(node.data >= x){
                ans = node.data;
                node = node.left;
            }
            else node = node.right;
            
        }
        
        return ans;
    }

}
