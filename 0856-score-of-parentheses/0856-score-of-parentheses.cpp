class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        stk.push(0);

        for(char c : s) {
            if(c == '(') {
                stk.push(0);
            }else {
                int curr = stk.top();
                stk.pop();

                stk.top() += max(1, 2 * curr);
            }
        }

        return stk.top();
    }
};