class Solution {
    public int maxAdjacentDistance(int[] nums) {
        int ans = 0 ;

        for(int i = 0 ; i < nums.length-1 ; i++) {
            int a, b ;

            if(nums[i] > nums[i+1]) {
                a = nums[i] ;
                b = nums[i+1] ;
            }else{
                b = nums[i] ;
                a = nums[i+1] ;
            }

            if(ans < (a - b) ) {
                ans = (a - b) ;
            }
        }

        int diff = nums[0] - nums[nums.length-1] ;
        if(ans < Math.abs(diff) ) {
            ans = Math.abs(diff) ; 
        }
        return ans ;
    }
}