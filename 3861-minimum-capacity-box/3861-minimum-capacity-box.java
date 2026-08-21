class Solution {
    public int minimumIndex(int[] capacity, int itemSize) {
        int ans = -1 ;

        for(int i = 0 ; i < capacity.length ; i++) {
            if(itemSize <= capacity[i]) {
                if(ans == -1) {
                    ans = i ;
                }else if(capacity[ans] > capacity[i]) {
                    ans = i ;
                }
            }
        }

        return ans ;
    }
}