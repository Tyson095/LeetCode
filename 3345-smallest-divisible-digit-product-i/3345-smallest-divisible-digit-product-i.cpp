class Solution {
public:
    int smallestNumber(int n, int t) {
        
        while(n < INT_MAX) {
            int temp = n, prd = 1 ;
            while(temp) {
                prd *= (temp%10) ;
                temp /= 10 ;
            }

            if(prd % t == 0) {
                return n ;
            }
            n++ ;
        }

        return -1 ;
    }
};