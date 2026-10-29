class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int i, vector<bool>& vis) {
        vis[i] = true;

        for(int j = 0; j < isConnected.size(); j++) {
            if(isConnected[i][j] && !vis[j]) {
                dfs(isConnected, j, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ans = 0;
        vector<bool> vis(n, false);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] && !vis[i]) {
                    dfs(isConnected, i, vis);
                    ans++;
                }
            }
        }

        return ans;
    }
};