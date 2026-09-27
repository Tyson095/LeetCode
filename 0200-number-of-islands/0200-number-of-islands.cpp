class Solution {
public:
    void helper(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0' || vis[i][j]) {
            return;
        }
        vis[i][j] = true;

        helper(i+1, j, grid, vis);
        helper(i-1, j, grid, vis);
        helper(i, j+1, grid, vis);
        helper(i, j-1, grid, vis);
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    helper(i, j, grid, vis);
                    ans++;
                }
            }
        }

        return ans;
    }
};