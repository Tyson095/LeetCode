class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long ways(vector<int>& a, vector<vector<long long>>& C) {
        int n = a.size();
        if(n <= 2) {
            return 1;
        }
        vector<int> l, r;
        
        for(int i = 1; i < n; i++) {
            if (a[i] < a[0]) l.push_back(a[i]);
            else r.push_back(a[i]);
        }
        
        return C[n - 1][l.size()] * ways(l, C) % MOD * ways(r, C) % MOD;
    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> temp(n + 1, vector<long long>(n + 1, 0));

        for(int i = 0; i <= n; i++) {
            temp[i][0] = 1;
            for(int j = 1; j <= i; j++) {
                temp[i][j] = (temp[i - 1][j - 1] + temp[i - 1][j]) % MOD;
            }
        }
        return (ways(nums, temp) - 1 + MOD) % MOD;
    }
};