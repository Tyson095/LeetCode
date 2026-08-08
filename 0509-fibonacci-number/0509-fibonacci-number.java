class Solution {
    public int fib(int n) {
        int term1 = 0 ;
        int term2 = 1 ;

        if(n == 0){
            return term1 ;
        }

        for(int i = 2 ; i <= n ; i++) {
            int sum = term1 + term2 ;
            term1 = term2 ;
            term2 = sum ;
        }

        return term2 ;
    }
}