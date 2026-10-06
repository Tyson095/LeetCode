class Solution {
public:
    void helper(vector<string>& ans, string temp, int n, int r, int l) {
        if(temp.size() == 2 * n) {
            ans.push_back(temp);
            return;
        }

        if(r < n) {
            temp += '(';
            helper(ans, temp, n, r+1, l);
            temp.pop_back();
        }

        if(l < r) {
            temp += ')';
            helper(ans, temp, n, r, l+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;

        helper(ans, temp, n, 0, 0);

        return ans;
    }
};