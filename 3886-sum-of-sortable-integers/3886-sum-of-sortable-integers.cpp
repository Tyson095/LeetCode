class Solution {
public:
    int sortableIntegers(std::vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        for(int k = 1; k <= n; k++) {
            if (n % k != 0) {
                continue;
            }
            
            bool valid = true;
            int prevMax = INT_MIN;
            
            for(int start = 0; start < n; start += k) {
                int currentMin = INT_MAX;
                int currentMax = INT_MIN;
                int descents = 0;
                
                for(int j = start; j < start + k; j++) {
                    currentMin = min(currentMin, nums[j]);
                    currentMax = max(currentMax, nums[j]);
                    if(j > start && nums[j - 1] > nums[j]) {
                        descents++;
                    }
                }
                
                if(descents > 1 || (descents == 1 && nums[start + k - 1] > nums[start]) || prevMax > currentMin) {
                    valid = false;
                    break;
                }
                prevMax = currentMax;
            }
            
            if(valid) {
                ans += k;
            }
        }
        return ans;
    }
};
