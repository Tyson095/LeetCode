class Solution {
public:
    bool fnd(int i, int j, int idx, vector<vector<char>>& board, string word) {
        if(i >= board.size() || j >= board[0].size() || i < 0 || j < 0 || board[i][j] != word[idx]) return false ;

        if(idx == word.size()-1 && board[i][j] == word[idx]) {
            return true ;
        }

        char temp = board[i][j] ;
        board[i][j] = '#' ;

        if(fnd(i+1, j, idx+1, board, word) || fnd(i, j+1, idx+1, board, word) ||
           fnd(i-1, j, idx+1, board, word) || fnd(i, j-1, idx+1, board, word)) {
            return true ;
        }

        board[i][j] = temp ;
        return false ;
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i = 0 ; i < board.size() ; i++) {
            for(int j = 0 ; j < board[0].size() ; j++) {
                if(fnd(i, j, 0, board, word)) {
                    return true ;
                }
            }
        }

        return false ;
    }
};