class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int even = 0;

        for(int i : nums) {
            if(i % 2 == 0) {
                even++;
            }
        }

        for(int i = 0, j = even; i < even || j < nums.size(); i++, j++) {
            if(i < even) {
                nums[i] = 0;
            }
            if(j < nums.size()) {
                nums[j] = 1;
            }
        }

        return nums;
    }
};