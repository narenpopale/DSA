
class Node {
    String data;
    Node next;

    Node(String data) {
        this.data = data;
        this.next = null;
    }
}

public class CycleInLL {

    // 1. Detect Cycle in a LinkedList
    // Given head, the head of a linked list, determine if the linked list has a
    // cycle in it.
    // Return true if there is a cycle in the linked list. Otherwise, return false.

    // Approach - Slow and Fast Pointer
    // TC - O(N)
    // SC - O(1)
    
    public boolean hasCycle(Node head) {
        if (head == null || head.next == null)
            return false;

        Node fast = head, slow = head;

        while (fast.next != null && fast.next.next != null) {
            fast = fast.next.next;
            slow = slow.next;
            if (fast == slow)
            return true;
        }

        return false;
    }
    
    
    // 2. Find Starting Point of Cycle in LL
    // Given the head of a linked list, return the node where the cycle begins.
    // If there is no cycle, return null.

    // Approach - Slow and Fast Pointer
    // TC - O(N)
    // SC - O(1)

    static Node findStartingPointOfCycle(Node head) {
        if (head == null || head.next == null)
            return null;

        Node fast = head;
        Node slow = head;
        Node entry = head;

        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast) {
                while (slow != entry) {
                    slow = slow.next;
                    entry = entry.next;
                }
                return slow;
            }
        }
        return null;
    }

}