// Reverse a LinkedList
// Given the head of a singly linked list, reverse the list, and return the reversed list.

// TC - O(N)

class Node {
    String data;
    Node next;

    Node(String data) {
        this.data = data;
        this.next = null;
    }
}

public class ReversLL {

    // Iterative Solution
    public Node reverseLL(Node head) {
        Node prev = null;

        while (head != null) {
            Node next = head.next;
            head.next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }


    // Recursive Solution
    Node reverseRec(Node prev, Node head){
        if(head == null) return prev;

        Node next = head.next;
        head.next = prev;

        return reverseRec(head, next);
    }

    public Node reverseList(Node head) {
        
        return reverseRec(null, head);

    }

}