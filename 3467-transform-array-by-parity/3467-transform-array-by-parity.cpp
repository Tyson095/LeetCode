class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int even = 0 ;
        vector<int> ans ;

        for(int i : nums) {
            if(i % 2 == 0) {
                even++ ;
                ans.push_back(0) ;
            }
        }

        for(int i = even ; i < nums.size() ; i++) {
            ans.push_back(1) ;
        }

        return ans ;
    }
};