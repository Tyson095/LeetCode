class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int idx = nums[0] > nums[1] ? 0 : -1 ;
        idx = nums[nums.size()-1] > nums[nums.size()-2] ? nums.size()-1 : -1 ; 
        long long lSum = 0, rSum = 0 ;
        for(int i = 1 ; i < nums.size()-1 ; i++) {
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                idx = i ;
            }
        }

        for(int i = 0 ; i <= idx ; i++) {
            lSum += (long long)nums[i] ;
        }

        for(int i = idx ; i < nums.size() ; i++) {
            rSum += (long long)nums[i] ;
        }

        if(lSum > rSum) {
            return 0 ;
        }
        else if(lSum < rSum) {
            return 1 ;
        }

        return -1 ;
    }
};