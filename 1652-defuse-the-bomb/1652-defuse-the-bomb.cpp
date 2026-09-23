class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size() ;
        vector<int> ans(n, 0) ;
        if(k == 0) {
            return ans ;
        }else if(k > 0) {
            int sum = 0 ;
            for(int i = 0 ; i < k ; i++) {
                sum += code[i] ;
            }

            for(int i = 0 ; i < n ; i++) {
                sum -= code[i] ;
                int idx = (i + k) % n ;

                sum += code[idx] ;

                ans[i] = sum ;
            }
        }else{
            k = k * (-1) ;
            int sum = 0 ;
            for(int i = n-1 ; i >= n-k ; i--) {
                sum += code[i] ;
            }

            for(int i = 0 ; i < n ; i++) {
                ans[i] = sum ;
                int idx = (n-k + i) % n ;
                sum -= code[idx] ;
                sum += code[i] ;
            }
        }

        return ans ;
    }
};