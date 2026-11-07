class Solution {
public:
    long long countValidSubstrings(string s) {
        long long ans = 0;

        int lastA = -1;
        int lastAB = -1;
        int l = 0, r = 0;

        while(r < s.size()) {
            if(s[r] == 'a') {
                lastA = r;
            }else if(s[r] == 'b') {
                if(lastA != -1) {
                    lastAB = max(lastAB, lastA);
                }
            }else if(s[r] == 'c') {
                l = lastAB + 1;
            }

            ans += (long long)(r - l + 1);
            r++;
       }

       return ans;
    }
};