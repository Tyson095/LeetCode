class Solution {
public:
    ListNode* helper(ListNode* curr, ListNode* end) {
        ListNode* prev = NULL ;

        while(curr != end) {
            ListNode* nxt = curr->next ;

            curr->next = prev ;
            prev = curr ;
            curr = nxt ;
        }

        return prev ;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) {
            return head ;
        }
        ListNode* tail = head ;

        for(int i = 0 ; i < k ; i++) {
            if(tail == NULL) {
                return head ;
            }

            tail = tail->next ;
        }

        ListNode* newHead = helper(head, tail) ;
        head->next =  reverseKGroup(tail, k) ;

        return newHead ;
    }
};