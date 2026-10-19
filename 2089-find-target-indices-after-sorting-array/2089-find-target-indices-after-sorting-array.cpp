class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        int freq = 0;
        int lcount = 0;

        for(int i : nums) {
            if(i == target) {
                freq++;
            }else if(i < target) {
                lcount++;
            }
        }
        
        for(int i = 0; i < freq; i++) {
            ans.push_back(lcount++);
        }

        return ans;
    }
};