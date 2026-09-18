class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> start(26, -1) ;
        vector<int> end(26, -1) ;
        vector<string> ans ;

        for(int i = 0 ; i < s.size() ; i++) {
            int chr = s[i] - 'a' ;

            if(start[chr] == -1) {
                start[chr] = i ;
            }

            end[chr] = i ;
        }
        vector<bool> isValid(26, true) ;

        for(int i = 0 ; i < 26 ; i++) {
            if(start[i] != -1) {
                for(int j = start[i] ; j <= end[i] ; j++) {
                    if(start[s[j] - 'a'] < start[i]) {
                        isValid[i] = false ;
                        break ;
                    }

                    end[i] = max(end[i], end[s[j] - 'a']) ;
                }
            }
        }

        int lastIdx = s.size() ;

        for(int i = s.size()-1 ; i >= 0 ; i--) {
            int idx = s[i] - 'a' ;

            if(isValid[idx] && i == start[idx] && end[idx] < lastIdx) {
                lastIdx = i ;
                ans.push_back(s.substr(i, end[idx]-i+1)) ;
            }
        }

        return ans ;
    }
};