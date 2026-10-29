class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int current_winner = arr[0];
        int consecutive_wins = 0;
        
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > current_winner) {
                current_winner = arr[i];
                consecutive_wins = 1;
            } else {
                consecutive_wins++;
            }
            
            if (consecutive_wins == k) {
                return current_winner;
            }
        }
        
        return current_winner;
    }
};