class Solution {
    ListNode helper(ListNode curr, ListNode end) {
        ListNode prev = null ;

        while(curr != end) {
            ListNode nxt = curr.next ;

            curr.next = prev ;
            prev = curr ;
            curr = nxt ;
        }

        return prev ;
    }

    public ListNode reverseKGroup(ListNode head, int k) {
        if(head == null) {
            return head ;
        }
        ListNode tail = head ;

        for(int i = 0 ; i < k ; i++) {
            if(tail == null) {
                return head ;
            }

            tail = tail.next ;
        }

        ListNode newHead = helper(head, tail) ;
        head.next = reverseKGroup(tail, k) ;

        return newHead ;
    }
}