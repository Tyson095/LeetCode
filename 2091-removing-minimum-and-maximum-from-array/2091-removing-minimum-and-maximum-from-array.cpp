class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn = 0, mx = 0, ans = 0 ;

        // for(int i = 0 ; i < nums.size() ; i++) {
        //     mn = nums[mn] > nums[i] ? i : mn ;
        //     mx = nums[mx] < nums[i] ? i : mx ;
        // }

        mn = min_element(nums.begin(), nums.end()) - nums.begin() ;
        mx = max_element(nums.begin(), nums.end()) - nums.begin() ;
        
        int front = max(mn, mx) + 1 ;
        int back = nums.size() - min(mn, mx) ;

        int mix = (min(mn, mx) + 1) + (nums.size() - max(mx, mn)) ;

        return min(front, min(back, mix) ) ;
    }
};