class Solution {
public:
    int maxFreqSum(string s) {

        int freq[26] = {0};

        for(char ch : s) {
            freq[ch - 'a']++;
        }

        int max_vowel = 0;
        int max_conso = 0;

        for(int i = 0; i < 26; i++) {

            char ch = 'a' + i;

            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                max_vowel = max(max_vowel, freq[i]);
            }
            else {
                max_conso = max(max_conso, freq[i]);
            }
        }

        return max_vowel + max_conso;
    }
};