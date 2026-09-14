class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = 0 ;
        int mn = INT_MAX ;

        for(int i : nums1) {
            if(i % 2 != 0) {
                odd++ ;
            }

            mn = min(mn, i) ;
        }

        return mn % 2 != 0 || odd == 0 ;
    }
};