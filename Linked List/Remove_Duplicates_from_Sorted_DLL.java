// Given a sorted DLL. Return the head after removing duplicates.

// TC - O(N)
// SC - O(1)


    public static Node uniqueSortedList(Node head) {
        Node currNode = head;
        Node prevNode = head;
        int num = currNode.data;
        
       while(currNode != null) {
            if(num != currNode.data) {
                prevNode.next = currNode;
                prevNode = currNode;
                num = currNode.data;
            }
            currNode = currNode.next;
        }
        
        prevNode.next = null;
        
        return head;        
    }
