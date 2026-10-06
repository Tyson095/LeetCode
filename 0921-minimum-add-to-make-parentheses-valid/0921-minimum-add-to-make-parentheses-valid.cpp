class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0, open = 0;

        for(char c : s) {
            if(c == '(') {
                open++;
            }else {
                if(open > 0) {
                    open--;
                }else {
                    ans++;
                }
            }
        }
        
        ans += open;
        return ans;
    }
};