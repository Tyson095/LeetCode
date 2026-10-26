class Solution {
public:
    int minimumRecolors(string s, int k) {
        int w = 0;

        for(int i = 0; i < k; i++) {
            if(s[i] == 'W') {
                w++;
            }
        }

        if(w == 0) {
            return 0;
        }
        int ans = w;

        for(int i = 1; i <= s.size()-k; i++) {
            int l = s[i-1];
            int r = s[i+k-1];

            if(l == 'W') {
                w--;
            }
            if(r == 'W') {
                w++;
            }

            ans = min(ans, w);
        }

        return ans;
    }
};