class Solution {
public:
    int helper(vector<int>& nums, int idx, int currXOR) {
        if(idx == nums.size()) {
            return currXOR;
        }

        return helper(nums, idx+1, currXOR ^ nums[idx]) + helper(nums, idx+1, currXOR);
    }

    int subsetXORSum(vector<int>& nums) {
        return helper(nums, 0, 0);
    }
};