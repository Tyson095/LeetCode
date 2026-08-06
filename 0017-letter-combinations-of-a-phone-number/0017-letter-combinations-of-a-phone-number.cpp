class Solution {
public:
    void solve(string digits, int idx, map<char, string> m, vector<string>& ans, string temp) {
        if(idx >= digits.size()) {
            ans.push_back(temp) ;
            return ;
        }

        char n = digits[idx] ;

        for(int i = 0 ; i < m[n].size() ; i++) {
            temp.push_back(m[n][i]) ;
            solve(digits, idx+1, m, ans, temp) ;

            temp.pop_back() ;
        }
    }

    vector<string> letterCombinations(string digits) {
        map<char, string> m = {{'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"}, {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}} ;
        vector<string> ans ;
        string temp ;

        int idx = 0 ;

        solve(digits, idx, m, ans, temp) ;

        return ans ;
    }
};