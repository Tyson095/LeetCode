class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int odd = 0, mn = INT_MAX ;

        for(int i : nums) {
            if(i % 2 != 0) {
                odd++ ;
            }

            mn = min(i, mn) ;
        }

        return mn % 2 != 0 || odd == 0 ;
    }
};