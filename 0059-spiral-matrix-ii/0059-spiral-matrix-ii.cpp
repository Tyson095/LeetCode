class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n, vector<int>(n, 0)) ;

        int rSt = 0, cSt = 0, rend = n-1, cend = n-1 ;

        int x = 1 ;
        while(rSt <= rend && cSt <= cend) {
            for(int i = cSt ; i <= cend ; i++) {
                ans[rSt][i] = x++ ;
            }

            rSt++ ;

            for(int i = rSt ; i <= rend ; i++) {
                ans[i][cend] = x++ ;
            }

            cend-- ;

            for(int i = cend ; i >= cSt ; i--) {
                ans[rend][i] = x++ ;
            }

            rend-- ;

            for(int i = rend ; i >= rSt ; i--) {
                ans[i][cSt] = x++ ;
            }

            cSt++ ;
        }

        return ans ;
    }
};