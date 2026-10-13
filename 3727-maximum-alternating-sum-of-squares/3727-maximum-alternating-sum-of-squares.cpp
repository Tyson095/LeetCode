class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            nums[i] = nums[i]*nums[i];
        }

        sort(nums.begin(), nums.end());

        int l = 0, r = n-1;

        while(l <= r) {
            if(r == l) {
                ans += nums[r--];
            }else {
                ans += nums[r--] - nums[l++];
            }
        }

        return ans;
    }
};