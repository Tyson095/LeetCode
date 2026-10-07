class Solution {
public:
    bool digitCount(int n) {
        int count = 0;

        while(n > 0) {
            n /= 10;
            count++;
        }

        return count % 2 == 0;
    }
    int findNumbers(vector<int>& nums) {
        int ans = 0;

        for(int i : nums) {
            if(digitCount(i)) {
                ans++;
            }
        }

        return ans;
    }
};