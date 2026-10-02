class Solution {
public:
    void helper(vector<string>& ans, string& temp, int l, int r, int n) {
        if(temp.size() == 2 * n) {
            ans.push_back(temp);
            return;
        }

        if(r < n) {
            temp += '(';
            helper(ans, temp, l, r+1, n);

            temp.pop_back();
        }

        if(l < r) {
            temp += ')';
            helper(ans, temp, l+1, r, n);

            temp.pop_back();
        }

        
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;

        helper(ans, temp, 0, 0, n);

        return ans;
    }
};