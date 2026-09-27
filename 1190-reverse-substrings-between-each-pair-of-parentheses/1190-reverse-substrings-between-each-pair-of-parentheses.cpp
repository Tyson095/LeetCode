class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> openBrackets;
        string ans = "";

        for (char c : s) {
            if (c == '(') {
                openBrackets.push(ans.length());
            } else if (c == ')') {
                int st = openBrackets.top();
                openBrackets.pop();
                reverse(ans.begin() + st, ans.end());
            } else {
                ans += c;
            }
        }

        return ans;
    }
};
