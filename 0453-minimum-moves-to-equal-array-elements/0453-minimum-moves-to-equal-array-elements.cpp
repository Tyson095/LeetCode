class Solution {
public:
    int minMoves(vector<int>& nums) {
        int moves = 0;
        int mn = *min_element(nums.begin(), nums.end());

        for(int i : nums) {
            moves += (i - mn);
        }

        return moves;
    }
};