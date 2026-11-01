class Solution {
public:
    long long helper(vector<int>& nums, int maxVal) {
        long long ans = 0;
        for(int i = 0, j = nums.size() - 1; i < j; i++) {
            while(i < j && nums[i] + nums[j] > maxVal) {
                j--;
            }
            ans += (long long)(j-i);
        }

        return ans;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());

        return helper(nums, upper) - helper(nums, lower-1);
    }
};