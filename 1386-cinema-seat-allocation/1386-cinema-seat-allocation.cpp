class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = n * 2 ;
        sort(reservedSeats.begin(), reservedSeats.end()) ;

        for(int i = 0 ; i < reservedSeats.size() ; i++) {
            int curr = reservedSeats[i][0] ;

            bool r25 = false ;
            bool r47 = false ;
            bool r69 = false ;

            while(i < reservedSeats.size() && curr == reservedSeats[i][0]) {
                int seat = reservedSeats[i][1] ;
                if(seat >= 2 && seat <= 5) {
                    r25 = true ;
                    if(seat >= 4 && seat <= 5) {
                        r47 = true ;
                    }
                }else if(seat >= 6 && seat <= 9) {
                    r69 = true ;
                    if(seat >= 6 && seat <= 7) {
                        r47 = true ;
                    }
                }
                i++ ;
            }

            if(r25 && r47 && r69) {
                ans -= 2 ;
            }else if(r25 || r47 || r69) {
                ans-- ;
            }
            i-- ;
        }

        return ans ;
    }
};