                        // Method - 2
class Solution {
public:
    string convert(string s, int n) {
        if(n == 1 || n >= s.size()) {
            return s;
        }
        
        vector<string> temp(n);

        for(int i = 0; i < s.size();) {
            for(int j = 0; j < n && i < s.size(); j++) {
                temp[j] += s[i++];
            }

            for(int j = n-2; i < s.size() && j > 0; j--) {
                temp[j] += s[i++];
            }
        }

        string ans;

        for(auto i : temp) {
            ans += i;
        }

        return ans;
    }
};