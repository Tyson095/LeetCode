class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size(), r;
        int N = n * n;
        int sum = N*(N+1) / 2, aSum = 0;

        unordered_set<int> s;

        for(int i=0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(s.find(grid[i][j]) != s.end()) {
                    r = grid[i][j];
                    continue ;
                }
                aSum += grid[i][j];
                s.insert(grid[i][j]);
            }
        }

        return {r, sum-aSum};
    }
};