class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans ;
        unordered_map<string, string> m ;

        for(auto i : knowledge) {
            m[i[0]] = i[1] ;
        }

        for(int i = 0 ; i < s.size() ; i++) {
            while(i < s.size() && s[i] != '(') {
                ans += s[i++] ;
            }

            if(s[i] == '(') {
                i++ ;

                string toFind = "" ;
                while(s[i] != ')') {
                    toFind += s[i++] ;
                }
                
                if(m.find(toFind) == m.end()) {
                    ans += '?' ;
                }else {
                    ans += m[toFind] ;
                }
            }
        }

        return ans ;
    }
};