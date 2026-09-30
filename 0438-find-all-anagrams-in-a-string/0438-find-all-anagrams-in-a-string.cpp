class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size();
        int m = p.size();

        if (m > n) {
            return ans;
        }

        vector<int> check(26, 0);
        vector<int> freq(26, 0);

        for (int i = 0; i < m; i++) {
            check[p[i] - 'a']++;
            freq[s[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (check[i] == freq[i]) {
                matches++;
            }
        }

        if (matches == 26) {
            ans.push_back(0);
        }

        for (int i = 1; i <= n - m; i++) {
            int left_idx = s[i - 1] - 'a';
            int right_idx = s[i + m - 1] - 'a';

            if (freq[left_idx] == check[left_idx]) {
                matches--;
            }
            freq[left_idx]--;
            if (freq[left_idx] == check[left_idx]) {
                matches++;
            }

            if (freq[right_idx] == check[right_idx]) {
                matches--;
            }
            freq[right_idx]++;
            if (freq[right_idx] == check[right_idx]) {
                matches++;
            }

            if (matches == 26) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
