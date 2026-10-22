class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) {
            return 0;
        }

        int idx = -1;             // index of 0
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                idx = i;
                break;
            }
        }

        bool is_cyclic_inc = true;
        for (int k = 0; k < n; k++) {
            if (nums[(idx + k) % n] != k) {
                is_cyclic_inc = false;
                break;
            }
        }

        bool is_cyclic_dec = true;
        for (int k = 0; k < n; k++) {
            if (nums[(idx - k + n) % n] != k) {
                is_cyclic_dec = false;
                break;
            }
        }

        int ans = INT_MAX;

        if (is_cyclic_inc) {
            int optA = idx;
            int optB = (n - idx) % n + 2; 
            
            ans = min(ans, min(optA, optB));
        }

        if (is_cyclic_dec) {
            int optC = (idx + 1) % n + 1;       // rotate left (idx+1) times, then reverse
            int optD = n - idx;                 // reverse, then rotate left (n-1-idx) times
            
            ans = min(ans, min(optC, optD));
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};