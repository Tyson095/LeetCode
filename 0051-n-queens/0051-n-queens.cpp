class Solution {
public:
    bool check(int i, int j, vector<string>& temp, int n) {

        for(int x = 0 ; x < n ; x++) {
            if(x != i && temp[x][j] == 'Q') {
                return false ;
            }
            if(x != j && temp[i][x] == 'Q') {
                return false ;
            }
        }

        for(int x = i, y = j ; x >= 0 && y >= 0 ; x--,y--) {
            if(x != i && y != j && temp[x][y] == 'Q') {
                return false ;
            }
        }

        for(int x = i, y = j ; x >= 0 && y < n ; x--,y++) {
            if(x != i && y != j && temp[x][y] == 'Q') {
                return false ;
            }
        }

        return true ;
    }

    void solve(vector<vector<string>>& ans, vector<string>& temp, int i, int n) {
        if(i == n) {
            ans.push_back(temp) ;
            return ;
        }

        for(int j = 0 ; j < n ; j++) {
            temp[i][j] = 'Q' ;
            if(check(i, j, temp, n)) {
                solve(ans, temp, i+1, n) ;
            }

            temp[i][j] = '.' ;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans ;
        vector<string> temp(n, string(n, '.')) ;

        solve(ans, temp, 0, n) ;
        return ans ;
    }
};