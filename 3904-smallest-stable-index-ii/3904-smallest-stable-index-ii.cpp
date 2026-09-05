class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int currMax = INT_MIN, n = nums.size() ;
        vector<int> mn(n, 0) ;
        mn[n-1] = nums[n-1] ;

        for(int i = n-2 ; i >= 0 ; i--) {
            mn[i] = min(mn[i+1], nums[i]) ;
        }

        for(int i = 0 ; i < n ; i++) {
            currMax = max(currMax, nums[i]) ;

            if(currMax - mn[i] <= k) {
                return i ;
            }
        }

        return -1 ;
    }
};