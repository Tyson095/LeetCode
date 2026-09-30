class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if(m < n) {
            return false;
        }

        vector<int> check(26, 0);
        vector<int> freq(26, 0);

        for(int i = 0; i < n; i++) {
            check[s1[i] - 'a']++;
            freq[s2[i] - 'a']++;
        }

        int matches = 0;

        for(int i = 0; i < 26; i++) {
            if(check[i] == freq[i]) {
                matches++;
            }
        }

        if(matches == 26) {
            return true;
        }

        for(int i = 1; i <= m-n; i++) {
            int l = s2[i-1] - 'a';
            int r = s2[i+n-1] - 'a';

            if(freq[l] == check[l]) {
                matches--;
            }
            freq[l]--;

            if(freq[l] == check[l]) {
                matches++;
            }

            if(freq[r] == check[r]) {
                matches--;
            }
            freq[r]++;

            if(freq[r] == check[r]) {
                matches++;
            }

            if(matches == 26) {
                return true;
            }
        }

        return false;
    }
};