class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        unsigned long long int total = 0, first = 0, ans = 0 ;

        for(int i : nums) {
            total += (unsigned long long int) i ;
        }

        for(int i = 0 ; i < nums.size()/2 ; i++) {
            first += (unsigned long long int) nums[i] ;
        }

        if(first > total - first) {
            ans++ ;
        }

        for(int j = nums.size()/2 ; j < nums.size() ; j++) {
            first -= (unsigned long long int) nums[j - nums.size()/2] ;
            first += (unsigned long long int) nums[j] ;

            if(first > total - first) {
                ans++ ;
            }   
        }

        for(int i = 0 ; i < nums.size()/2 - 1 ; i++) {
            first -= (unsigned long long int) nums[i + nums.size()/2] ;
            first += (unsigned long long int) nums[i] ;

            if(first > total - first) {
                ans++ ;
            }   
        }

        return ans ;
    }
};