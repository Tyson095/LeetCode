class Solution {
public:
    string convert(string s, int n) {
        vector<vector<char>> temp(n);

        for(int i = 0; i < s.size(); i++) {
            for(int j = 0; j < n; j++) {
                if(i < s.size()) {
                    temp[j].push_back(s[i++]);
                }
            }

            for(int j = n-2; j > 0; j--) {
                if(i < s.size()) {
                    temp[j].push_back(s[i++]);
                }
            }
            i--;
        }

        string ans;

        for(auto i : temp) {
            for(auto c : i) {
                ans += c;
            }
        }

        return ans;
    }
};