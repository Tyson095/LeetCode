class Solution {
public:
int maxSum(vector<int>& nums, int k) {
    const long long MOD = 1e9 + 7;
    int freq[32] = {0};

    for(int x : nums) {
        for(int b = 0; b < 32; b++) {
            if(x >> b & 1) {
                freq[b]++;
            }
        }
    }

    long long ans = 0;
    for(int i = 0; i < k; i++) {
        long long cur = 0;
        for(int b = 0; b < 32; b++) {
            if(freq[b] > 0) {
                cur |= (1LL << b);
                freq[b]--;
            }
        }
        ans = (ans + cur * cur) % MOD;
    }
    return (int)ans;
    }
};