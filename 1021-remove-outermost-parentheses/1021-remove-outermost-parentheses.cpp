class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int count = 0;
        int l = 0, r = 0;

        for(; r < s.size(); r++) {
            if(s[r] == '(') {
                count++;
            }else {
                count--;
                if(count == 0) {
                    string temp(s.begin()+l+1, s.begin()+r);
                    l = r+1;
                    ans += temp;
                }
            }
        }

        return ans;
    }
};