class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size();
        int m = p.size();

        if(m > n) return ans;

        int chrp[26] = {0};
        int chrs[26] = {0};

        for(int i = 0; i < m; i++) {
            chrp[p[i]-'a']++;
            chrs[s[i]-'a']++;
        }

        int matches = 0;

        for(int i = 0; i < 26; i++) {
            if(chrp[i] == chrs[i]) {
                matches++;
            }
        }

        if(matches == 26) {
            ans.push_back(0);
        }

        for(int i = 1; i <= n-m; i++) {
            int l = s[i-1] - 'a';
            int r = s[i+m-1] - 'a';

            if(chrs[l] == chrp[l]) {
                matches--;
            }
            chrs[l]--;
            if(chrs[l] == chrp[l]) {
                matches++;
            }

            if(chrs[r] == chrp[r]) {
                matches--;
            }
            chrs[r]++;
            if(chrs[r] == chrp[r]) {
                matches++;
            }

            if(matches == 26) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};