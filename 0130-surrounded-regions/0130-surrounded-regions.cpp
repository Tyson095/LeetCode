class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<bool>>& vis) {
        int n = board.size();
        int m = board[0].size();

        if (r < 0 || r >= n || c < 0 || c >= m)
            return ;

        if (vis[r][c] || board[r][c] == 'X')
            return ;

        vis[r][c] = true;

        dfs(r + 1, c, board, vis);
        dfs(r - 1, c, board, vis);
        dfs(r, c + 1, board, vis);
        dfs(r, c - 1, board, vis);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // First column + last column
        for (int i = 0 ; i < n ; i++) {

            if (board[i][0] == 'O')
                dfs(i, 0, board, vis);

            if (board[i][m - 1] == 'O')
                dfs(i, m - 1, board, vis);
        }

        // First row + last row
        for (int j = 0 ; j < m ; j++) {

            if(board[0][j] == 'O')
                dfs(0, j, board, vis);

            if(board[n - 1][j] == 'O')
                dfs(n - 1, j, board, vis);
        }

        // Capture all unsafe O's
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if(board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};