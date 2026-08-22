class Solution {
    public boolean checkDivisibility(int n) {
        int sum = 0, prd = 1, temp = n ;
        
        while(temp > 0) {
            sum += temp % 10 ;
            prd *= temp % 10 ;

            temp /= 10 ;
        }

        return (n % (sum + prd) == 0) ;
    }
}