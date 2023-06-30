
// Given a BST and a number X, find floor of X.
// Note: Floor(X) is a number that is either equal to X or is immediately lesser than X.


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

public class Floor_in_BST {
    
    int floor(Node root, int x) {

        int ans = -1;
        Node node = root;
        
        while(node != null){
            
            if(node.data <= x){
                ans = node.data;
                node = node.right;
            }
            else node = node.left;
            
        }
        
        return ans;
    }

}
