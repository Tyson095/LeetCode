class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans = 0 ;

        for(int i = 0 ; i < nums.size() ; i++) {
            if(i == nums.size()-1) {
                ans = max(ans, abs(nums[0] - nums[i])) ;
            }else{
                ans = max(ans, abs(nums[i] - nums[i+1])) ;
            }
        }

        return ans ;
    }
};