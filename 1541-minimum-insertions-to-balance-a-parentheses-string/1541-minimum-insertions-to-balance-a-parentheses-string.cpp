class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        stack<char> stk;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ')') {
                if(s[i+1] == ')'){
                    i++;
                    if(stk.size() > 0) {
                        stk.pop();
                    }else {
                        ans++;
                    }
                }else{
                    if(stk.size() > 0) {
                        stk.pop();
                        ans++;
                    }else {
                        ans += 2;
                    }
                }
            }else {
                stk.push(s[i]);
            }
        }

        return ans + stk.size()*2;
    }
};