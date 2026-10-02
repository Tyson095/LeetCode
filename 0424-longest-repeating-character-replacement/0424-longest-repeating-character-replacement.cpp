class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int freq[26] = {0};

        int maxLen = 0;
        int maxFreq = 0;
        int l = 0, r = 0;

        while(r < n) {
            char c = s[r];

            freq[c - 'A']++;
            maxFreq = max(maxFreq, freq[c - 'A']);

            if ((r - l + 1) - maxFreq > k) {
                freq[s[l] - 'A']--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};