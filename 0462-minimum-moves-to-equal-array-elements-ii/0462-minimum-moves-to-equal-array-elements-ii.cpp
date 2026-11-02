class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mdn = nums[nums.size()/2], sum = 0;

        for(int i : nums) {
            sum += abs(i-mdn);
        }

        return sum;
    }
};