class Solution {
public:
    bool isValid(string s) {
        int balance = 0;

        for(char i : s) {
            if(i == '(') {
                balance++;
            }else if(i == ')') {
                balance--;
                if(balance < 0) {
                    return false;
                }
            }
        }

        return true;
    }

    void helper(string& s, unordered_set<string>& str, int idx, int rmopen, int rmclose, string& curr) {
        if(idx == s.size()) {
            if(rmclose == 0 && rmopen == 0 && isValid(curr)) {
                str.insert(curr);
            }
            return;
        }

        if(rmopen > 0 && s[idx] == '(') {
            helper(s, str, idx+1, rmopen-1, rmclose, curr);
        }
        if(rmclose > 0 && s[idx] == ')') {
            helper(s, str, idx+1, rmopen, rmclose-1, curr);
        }

        curr += s[idx];
        helper(s, str, idx+1, rmopen, rmclose, curr);
        curr.pop_back();
    }

    vector<string> removeInvalidParentheses(string s) {
        int rmopen = 0, rmclose = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                rmopen++;
            }else if(s[i] == ')') {
                rmopen--;
                if(rmopen < 0) {
                    rmopen = 0;
                }
            }
        }

        for(int i = s.size()-1; i >= 0; i--) {
            if(s[i] == ')') {
                rmclose++;
            }else if(s[i] == '(') {
                rmclose--;
                if(rmclose < 0) {
                    rmclose = 0;
                }
            }
        }

        unordered_set<string> str;
        string curr;
        helper(s, str, 0, rmopen, rmclose, curr);

        vector<string> ans(str.begin(), str.end());

        return ans;
    }
};