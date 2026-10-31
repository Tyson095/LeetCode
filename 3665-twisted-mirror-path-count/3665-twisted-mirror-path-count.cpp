class Solution {
public:
    int n, m;
    const int MOD = 1e9 + 7;
    int dfs(vector<vector<int>>& grid, int i, int j, int last, vector<vector<vector<int>>>& dp) {
        if(i >= n || j >= m) {
            return 0;
        }
        
        if(dp[i][j][last] != -1) {
            return dp[i][j][last] % MOD;
        }

        if(i == n-1 && j == m-1) {
            return 1;
        }

        int ans = 0;
        if(grid[i][j] == 1) {
            if(last == 0) {
                return dp[i][j][last] = dfs(grid, i+1, j, 1, dp);
            }else if(last == 1) {
                return dp[i][j][last] = dfs(grid, i, j+1, 0, dp);
            }
        }else {
            ans = (dfs(grid, i, j+1, 0, dp) + dfs(grid, i+1, j, 1, dp))% MOD;
        }

        return dp[i][j][last] = ans;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2, -1)));  //store how many ways we can reach m-1, n-1 from i, j

        return dfs(grid, 0, 0, 0, dp);              // last(last move) -> -1 for starting, 0 -> right, 1 -> down
    }
};