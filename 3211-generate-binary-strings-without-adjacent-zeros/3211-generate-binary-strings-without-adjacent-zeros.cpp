class Solution {
public:
    void helper(vector<string>& ans, string temp, int n) {
        if(temp.size() == n) {
            ans.push_back(temp) ;
            return ;
        }

        if(temp.size() > 0 && temp.back() == '0') {
            helper(ans, temp+'1', n) ;
        }else {
            helper(ans, temp+'0', n) ;
            helper(ans, temp+'1', n) ;
        }
    }

    vector<string> validStrings(int n) {
        vector<string> ans ;
        string temp ;

        helper(ans, temp, n) ;

        return ans ;
    }
};