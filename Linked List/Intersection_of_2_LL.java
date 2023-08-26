// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. 
// If the two linked lists have no intersection at all, return null.

// TC - O(2N)
// SC - O(1)


import java.util.*;

class Node {
    int num;
    Node next;
    Node(int val) {
        num = val;
        next = null;
    }
}

Node intersectionPresent(Node head1,Node head2) {
    Node d1 = head1;
    Node d2 = head2;
    
    while(d1 != d2) {
        d1 = d1 == null? head2:d1.next;
        d2 = d2 == null? head1:d2.next;
    }
    
    return d1;
}
