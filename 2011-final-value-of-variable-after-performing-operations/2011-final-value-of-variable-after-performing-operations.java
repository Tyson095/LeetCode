class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int ans = 0 ;

        for(String i : operations) {
            if(i.equals("++X")|| i.equals("X++")) {
                ans += 1 ;
            }else if(i.equals("--X") || i.equals("X--")) {
                ans -= 1 ;
            }
        }

        return ans ;
    }
}