class Solution {
    public boolean isPalindrome(int x) {
        int y = 0, n = x ;

        while(n > 0) {
            y = y*10 + (n % 10) ;
            n /= 10 ;
        }

        return y == x ;
    }
}