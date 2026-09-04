class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int idxDiff, int valDiff) {
        
        for(int i = 0 ; i < nums.size() ; i++) {
            for(int j = i + idxDiff ; j < nums.size() ; j++) {
                if(abs(nums[i] - nums[j]) >= valDiff) {
                    return {i, j} ;
                }
            }
        }

        return {-1, -1} ;
    }
};