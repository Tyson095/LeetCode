class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1} ;

        int idx = 1, firstCrit = -1, prevCrit = -1;

        ListNode* curr = head->next ;
        int prev = head->val ;

        while(curr->next != NULL) {
            int val = curr->val ;
            int nxt = curr->next->val ;

            if( (val > nxt && val > prev) || (val < nxt && val < prev) ) {
                if(prevCrit == -1) {
                    firstCrit = prevCrit = idx ;
                }
                else {
                    ans[0] = ans[0] == -1 ? idx-prevCrit : min(ans[0], idx-prevCrit) ;
                    prevCrit = idx ;
                }
                
            }

            curr = curr->next ;
            prev = val ;
            idx++ ;
        }

        if(ans[0] != -1) {
            ans[1] = prevCrit - firstCrit ;
        }

        return ans ;
    }
};