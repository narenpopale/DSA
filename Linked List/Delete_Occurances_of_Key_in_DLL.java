// Given a DLL and Key. Delete all occurances of key and return head.

// TC - O(N)
// SC - O(1)


    public static Node deleteAllOccurrences(Node head, int k) {
        
        Node currNode = head;

        while(currNode != null) {
            if(currNode.data == k) {
                Node prevNode = currNode.prev;
                Node nextNode = currNode.next;
                if(nextNode == null && prevNode == null) return null;
                else if(prevNode == null) {
                    nextNode.prev = null;
                    head = nextNode;
                }
                else if(nextNode == null) prevNode.next = null;          
                else {                    
                    prevNode.next = nextNode;
                    nextNode.prev = prevNode;
                }
                currNode = nextNode;
            }
            else currNode = currNode.next;
        }

        return head;
    }
