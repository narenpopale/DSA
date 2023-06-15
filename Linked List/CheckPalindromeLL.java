
// Check if LinkedList is Palindrome or not
// Given the head of a singly linked list, return true if it is a palindrome.

// Approach - Slow and Fast Pointer + Reverse LL
// TC - O(N/2) + O(N/2) + O(N/2)
// SC - O(1)

class Node {
    String data;
    Node next;

    Node(String data) {
        this.data = data;
        this.next = null;
    }
}

public class CheckPalindromeLL {

    // Reverse LL
    static Node reverse(Node head) {
        Node prev = null;

        while (head != null) {
            Node next = head.next;
            head.next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

    static boolean isPalindrome(Node head) {
        if (head == null || head.next == null)
            return true;

        Node slow = head;
        Node fast = head;

        // Find Middle of a LL
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // Reverse From Middle to the end of LL
        slow.next = reverse(slow.next);
        slow = slow.next;
        Node dummy = head;

        // Compare First half and Second half of LL
        while (slow != null) {
            if (dummy.data != slow.data)
                return false;
            dummy = dummy.next;
            slow = slow.next;
        }

        return true;
    }

}