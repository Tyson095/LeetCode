class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prd(nums.size(), 1);
        
        for (int i = 1 ; i < nums.size() ; i++) {
            prd[i] = prd[i-1] * nums[i-1] ;
        }

        int prdt = 1 ;

        for (int i = nums.size() - 1; i >= 0; i--) {
            prd[i] *= prdt ;
            prdt *= nums[i] ;
        }

        return prd ;
    }
};