class Solution {
public:
    int ans = 0;
    void helper(vector<int>& nums, int idx, int OR, int maxOR) {
        if(idx == nums.size()) {
            if(OR == maxOR) {
                ans++;
            }
            return;
        }

        helper(nums, idx+1, OR|nums[idx], maxOR);
        helper(nums, idx+1, OR, maxOR);
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        for(int i : nums) {
            maxOR |= i;
        }

        helper(nums, 0, 0, maxOR);
        return ans;
    }
};