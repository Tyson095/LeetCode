class Solution {
public:
    long long dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) {
            return 0;
        }

        long long sum = (long long)grid[i][j];
        grid[i][j] = 0;

        sum += (long long)dfs(grid, i-1, j);
        sum += (long long)dfs(grid, i+1, j);
        sum += (long long)dfs(grid, i, j-1);
        sum += (long long)dfs(grid, i, j+1);

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int ans = 0;
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] != 0 && dfs(grid, i, j) % k == 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};