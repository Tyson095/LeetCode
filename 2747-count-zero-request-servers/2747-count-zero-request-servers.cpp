class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int q = queries.size();
        vector<int> ans(q);
        sort(logs.begin(), logs.end(), compare);

        vector<vector<int>> sq(q);                 // (query time, original index)
        
        for(int i = 0; i < q; i++) {
            sq[i] = {queries[i], i};
        }
        sort(sq.begin(), sq.end());

        vector<int> cnt(n + 1, 0);
        int busy = 0, left = 0, right = 0, m = logs.size();

        for(auto& query : sq) {
            int t = query[0];
            int idx = query[1];

            while(right < m && logs[right][1] <= t) {
                if(cnt[logs[right][0]]++ == 0) {
                    busy++;
                }
                right++;
            }
            
            while(left < m && logs[left][1] < t - x) {
                if(--cnt[logs[left][0]] == 0) {
                    busy--;
                }
                
                left++;
            }
            
            ans[idx] = n - busy;
        }

        return ans;
    }
};