class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long ways(vector<int>& a, vector<vector<long long>>& coeff) {
        int n = a.size();
        if(n <= 2) {
            return 1;
        }
        vector<int> l, r;
        
        for(int i = 1; i < n; i++) {
            if (a[i] < a[0]) l.push_back(a[i]);
            else r.push_back(a[i]);
        }
        
        return coeff[n - 1][l.size()] * ways(l, coeff) % MOD * ways(r, coeff) % MOD;
    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> coeff(n + 1, vector<long long>(n + 1, 0));

        for(int i = 0; i <= n; i++) {
            coeff[i][0] = 1;
            for(int j = 1; j <= i; j++) {
                coeff[i][j] = (coeff[i - 1][j - 1] + coeff[i - 1][j]) % MOD;
            }
        }
        return(ways(nums, coeff) - 1 + MOD) % MOD;
    }
};