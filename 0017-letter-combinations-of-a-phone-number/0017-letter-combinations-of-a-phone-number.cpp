class Solution {
public:
    unordered_map<char, string> m = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    void helper(string digits, int idx, string& curr, vector<string>& ans) {
        if(idx == digits.size()) {
            ans.push_back(curr);
            return;
        }

        for(auto c : m[digits[idx]]) {
            curr += c;
            helper(digits, idx+1, curr, ans);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string curr;
        helper(digits, 0, curr, ans);

        return ans;
    }
};