class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ans = new ListNode();
        ans->next = head ;
        
        ListNode* curr = ans ;
        while (curr->next != NULL) {
            if (curr->next->val == val) {
                ListNode* toDelete = curr->next;
                curr->next = curr->next->next;
                delete toDelete;
            } else {
                curr = curr->next;
            }
        }
        
        ListNode* newHead = ans->next ;
        delete ans ;
    
    return newHead ;}
};
