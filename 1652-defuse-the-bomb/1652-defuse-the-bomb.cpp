class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size() ;
        vector<int> ans(n, 0) ;
        if(k == 0) {
            return ans ;
        }

        int st = k > 0 ? 1 : n + k ;
        int end = k > 0 ? k : n - 1 ;
        int sum = 0 ;

        for(int i = st ; i <= end ; i++) {
            sum += code[i] ;
        }

        for(int i = 0 ; i < code.size() ; i++) {
            ans[i] = sum ;

            sum -= code[(st + i) % n] ;
            sum += code[(end + i + 1) % n] ;
        }

        return ans ;
    }
};