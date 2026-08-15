class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans = nums.size() ;
        int totalXor = 0 ;
        bool nonZero = false ;

        for(int i : nums) {
            totalXor ^= i ;

            if(i != 0) {
                nonZero = true ;
            }
        }

        if(totalXor != 0) {
            return ans ;
        }

        if(nonZero) {
           return ans-1 ; 
        }

        return 0 ;
    }
};