class Solution {
public:
    bool helper(int src, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& recPath) {
        vis[src] = true;
        recPath[src] = true;

        for(auto v : adj[src]) {
            if(!vis[v]) {
                if(helper(v, adj, vis, recPath)) {
                    return true;
                }
            }else if(recPath[v]) {
                return true;
            }
        }
        
        recPath[src] = false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<bool> recPath = vis;
        vector<vector<int>> adj(n);
        
        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v); 
        }

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                if(helper(i, adj, vis, recPath)) {
                    return false;
                }
            }
        }

        return true;
    }
};