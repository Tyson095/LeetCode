class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0 ;
        int ans = INT_MAX ;

        for(int l = 0, r = 0 ; r < nums.size() ; r++) {
            sum += nums[r] ;

            while(sum >= target && l <= r) {
                ans = min(ans, r-l+1) ;
                sum -= nums[l++] ;
            }
        }

        return ans == INT_MAX ? 0 : ans ;
    }
};