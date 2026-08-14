class Solution {
public:
    int ans = 0 ;

    void helper(int st, int end, string s) {
        vector<int> freq(26, 0) ;
        for(int i = st ; i <= end ; i++) {
            freq[s[i] - 'a']++ ;
            if(freq[s[i] - 'a'] > 2)  {
                return ;
            }
        }

        ans = max(ans, (end-st+1)) ;
    }

    int maximumLengthSubstring(string s) {
        for(int i = 0 ; i < s.size() ; i++) {
            for(int j = 0 ; j < s.size() ; j++) {
                helper(i, j, s) ;
            }
        }

        return ans ;
    }
};