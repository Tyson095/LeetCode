class Solution {
    public int minimumIndex(int[] capacity, int itemSize) {
        int ans = -1 ;

        for(int i = 0 ; i < capacity.length ; i++) {
            if(capacity[i] >= itemSize) {
                if(ans == -1 || capacity[ans] > capacity[i]) {
                    ans = i ;
                }
            }
        }

        return ans ;
    }
}