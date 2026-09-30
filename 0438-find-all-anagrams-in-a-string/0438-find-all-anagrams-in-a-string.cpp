class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size();
        int m = p.size();

        if(m > n) {
            return ans;
        }
        
        vector<int> check(26, 0);
        vector<int> freq(26, 0);

        for(auto c : p) {
            check[c - 'a']++;
        }

        for(int i = 0; i < m; i++) {
            freq[s[i] - 'a']++;
        }

        if(freq == check) {
            ans.push_back(0);
        }

        for(int i = 1; i <= n-m ; i++) {
            freq[s[i-1] - 'a']--;
            freq[s[i+m-1] - 'a']++;

            if(freq == check) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};