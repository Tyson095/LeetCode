class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, mn = INT_MAX;

        for(int i : prices) {
            mn = min(mn, i);

            ans = max(ans, i-mn);
        }

        return ans;
    }
};