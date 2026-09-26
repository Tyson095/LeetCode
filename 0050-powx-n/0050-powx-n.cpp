class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long bin = n;

        if(n < 0) {
            bin = -bin;
            x = 1/x;
        }

        while(bin > 0) {
            if(bin % 2 == 1) {
                ans *= x;
            }

            x *= x;
            bin /= 2;
        }

        return ans;
    }
};