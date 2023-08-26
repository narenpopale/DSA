// Given the head of a linked list, return the list after sorting it in ascending order.

// TC - O(NlogN)
// SC - O(LogN)


public class ListNode {
  int val;
  ListNode next;
  ListNode() {}
  ListNode(int val) { this.val = val; }
  ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {

    public ListNode merge(ListNode left, ListNode right) {
        
        if(left == null)
            return right;
        
        if(right == null)
            return left;
        
        ListNode ans = new ListNode(-1);
        ListNode temp = ans;
        
        //merge 2 sorted Linked List
        while(left != null && right != null) {
            if(left.val < right.val ) {
                temp.next = left;
                temp = left;
                left = left.next;
            }
            else
            {
                temp.next = right;
                temp = right;
                right = right.next;
            }
        }
        
        while(left != null) {
            temp.next = left;
            temp = left;
            left = left.next;
        }
        
        while(right != null) {
            temp.next = right;
            temp = right;
            right = right.next;
        }
        
        ans = ans.next;
        return ans;
        
    }

    public ListNode findMid(ListNode head) {
        ListNode slow = head;
        ListNode fast = head.next;
        
        while(fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;
    }

    public ListNode sortList(ListNode head) {
        //base case
        if( head == null || head.next == null ) {
            return head;
        }
        
        // break linked list into 2 halvs, after finding mid
        ListNode mid = findMid(head);
        
        ListNode left = head;
        ListNode right = mid.next;
        mid.next = null;
        
        //recursive calls to sort both halves
        left = sortList(left);
        right = sortList(right);
        
        //merge both left and right halves
        ListNode result = merge(left, right);
        
        return result;
    }
}
