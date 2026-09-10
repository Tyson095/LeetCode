class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1" ;
        }
        string ans = "1" ;

        int i = 2 ;
        while(i <= n) {
            
            string temp = "";
            int count = 1 ;
            int j = 0 ;
            while (j+1 < ans.length()) {
                
                if(ans[j] == ans[j+1]) {
                    count++ ;
                }
                else {
                    temp += to_string(count) + ans[j] ;
                    count = 1 ;
                }

                j++ ;
            }

            temp += to_string(count) + ans[j] ;
            i++ ;

            ans = move(temp) ;
        }
        
        return ans ;
    }
};