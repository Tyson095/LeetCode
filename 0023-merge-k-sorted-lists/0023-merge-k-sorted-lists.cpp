/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> temp ;

        for(auto l : lists) {
            while(l != NULL) {
                temp.push_back(l->val) ;
                l = l->next ;
            }
        }

        sort(temp.begin(), temp.end()) ;

        ListNode* ans = new ListNode(0) ;
        ListNode* ptr = ans ;
        for(int i : temp) {
            ListNode* curr = new ListNode(i) ;
            ptr->next = curr ;
            ptr = curr ;
        }

        return ans->next ;
    }
};