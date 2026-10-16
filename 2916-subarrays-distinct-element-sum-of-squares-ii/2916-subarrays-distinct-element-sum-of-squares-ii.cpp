class Solution {
    int n;
    vector<long long> b1, b2;

    void add(int i, long long v1, long long v2) {
        for (; i <= n + 1; i += i & -i) { b1[i] += v1; b2[i] += v2; }
    }
    long long prefix(int x) {
        long long s1 = 0, s2 = 0;
        for (int i = x; i > 0; i -= i & -i) { s1 += b1[i]; s2 += b2[i]; }
        return s1 * x - s2;
    }

public:
    int sumCounts(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        n = nums.size();
        b1.assign(n + 2, 0);
        b2.assign(n + 2, 0);
        vector<int> last(*max_element(nums.begin(), nums.end()) + 1, 0);

        long long cur = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            int x = nums[i - 1], l = last[x] + 1;

            long long rangeSum = prefix(i) - prefix(l - 1);
            cur = (cur + 2 * rangeSum + (i - l + 1)) % MOD;
            ans = (ans + cur) % MOD;

            add(l, 1, l - 1);
            add(i + 1, -1, -i);
            last[x] = i;
        }
        return ans;
    }
};