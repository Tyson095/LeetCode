class Solution {
    public boolean uniformArray(int[] nums1) {
        int oddCount = 0, minElement = Integer.MAX_VALUE ;

        for(int i : nums1) {
            if(i % 2 != 0) {
                oddCount++ ;
            }

            if(i < minElement) {
                minElement = i ;
            }
        }

        return minElement % 2 != 0 || oddCount == 0 ;
    }
}