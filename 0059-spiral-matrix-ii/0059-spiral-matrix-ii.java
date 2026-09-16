class Solution {
    public int[][] generateMatrix(int n) {
        int[][] ans = new int[n][n] ;

        int left = 0, top = 0, right = n-1, bottom = n-1 ;
        int x = 1 ;

        while(left <= right && top <= bottom) {
            for(int i = left ; i <= right ; i++) {
                ans[top][i] = x++ ;
            }

            top++ ;

            for(int i = top ; i <= bottom ; i++) {
                ans[i][right] = x++ ;
            }

            right-- ;

            for(int i = right ; i >= left ; i--) {
                ans[bottom][i] = x++ ;
            }

            bottom-- ;

            for(int i = bottom ; i >= top ; i--) {
                ans[i][left] = x++ ;
            }

            left++ ;
        }

        return ans ;
    }
}