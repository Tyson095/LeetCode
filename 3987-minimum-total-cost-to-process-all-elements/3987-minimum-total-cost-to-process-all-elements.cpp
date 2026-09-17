class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long mod = 1e9 + 7 ;
        long long resources = k ;
        long long total_ops = 0 ;

        for(int i : nums) {
            if(i > resources) {
                long long needed = i - resources ;
                long long ops = (needed + k - 1) / k ;
                
                total_ops += ops ;
                resources += ops * k ;
            }
            resources -= i ;
        }

        // Division by 2 modulo (10^9 + 7) is equivalent to multiplying by 500000004.
        long long n = total_ops % mod ;
        long long next_n = (total_ops + 1) % mod ; // n * (n+1) / 2 
        long long ans = (n * next_n) % mod ;
        ans = (ans * 500000004) % mod ;

        return ans ;
    }
};
