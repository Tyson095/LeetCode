class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool ans = false ;

        while(n) {
            if(n % 2 == 1) {
                if(ans) {
                    return false ;
                }
                ans = true ;
            }

            n /= 2 ;
        }

        return ans ;
    }
};