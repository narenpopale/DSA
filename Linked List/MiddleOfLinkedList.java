// Problem - Middle of a LinkedList
// Given the head of a singly linked list, return the middle node of the linked list. 
// If there are two middle nodes, return the second middle node.


// Appraoch - Slow and Fast Pointer
// TC - O(N)


class ListNode {
    int data;
    ListNode next;

    ListNode(int data) {
        this.data = data;
        this.next = null;
    }
}

class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode slow = head, fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;
    }
}