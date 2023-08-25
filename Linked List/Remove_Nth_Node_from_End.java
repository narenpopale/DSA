// Given a linked list, and a number N. Find the Nth node from the end of this linked list and delete it. 
// Return the head of the new modified linked list.


// TC - O(N)
// SC - O(1)


public ListNode removeNthFromEnd(ListNode head, int n) {
    ListNode start = new ListNode();
    start.next = head;
    ListNode fast = start;
    ListNode slow = start;     
    
    for(int i = 1; i <= n; ++i)
    fast = fast.next;
        
    while(fast.next != null)
    {
    fast = fast.next;
    slow = slow.next;
    }
            
    slow.next = slow.next.next;
            
    return start.next;
}
