class Solution {
public:
    bool helper(vector<vector<int>>& grid, int i, int j, int x) {
        if(i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0 || grid[i][j] != x) {
            return false;
        }

        if(x == grid.size()*grid[0].size()-1) {
            return true;
        }

        return helper(grid , i - 2 , j - 1 , x + 1) ||
               helper(grid , i - 2 , j + 1 , x + 1) ||
               helper(grid , i - 1 , j - 2 , x + 1) ||
               helper(grid , i - 1 , j + 2 , x + 1) ||
               helper(grid , i + 1 , j + 2 , x + 1) ||
               helper(grid , i + 2 , j + 1 , x + 1) ||
               helper(grid , i + 2 , j - 1 , x + 1) ||
               helper(grid , i + 1 , j - 2 , x + 1);
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        return helper(grid, 0, 0, 0);
    }
};