class Solution {
public:
    int countAsterisks(string s) {
        int pair = 0, ans = 0;

        for(char c : s) {
            if(c == '|') {
                if(pair == 0) {
                    pair--;
                }else {
                    pair++;
                }
            }else if(c == '*') {
                if(pair == 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};