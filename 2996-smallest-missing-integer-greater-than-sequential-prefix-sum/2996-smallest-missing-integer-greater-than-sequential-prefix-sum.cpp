class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int ans = nums[0] ;
        unordered_set<int> s(nums.begin(), nums.end()) ;

        for(int i = 1 ; i < nums.size() ; i++) {
            if(nums[i] == nums[i-1] + 1) {
                ans += nums[i] ;
            }
            else {
                break ;
            }
        }

        while(true) {
            if(s.find(ans) == s.end()) {
                break ;
            }

            ans++ ;
        }

        return ans ;
    }
};