class Solution {
public:
    // dp states:
    // 0: unvisited
    // 1: visiting / in current recursion stack (detects cycle)
    // 2: safe
    // 3: unsafe (leads to a cycle)
    bool dfs(int src, vector<vector<int>>& graph, vector<int>& dp) {
        if(dp[src] != 0) {
            return dp[src] == 2;
        }
        
        dp[src] = 1; 
        
        for(int v : graph[src]) {
            if(dp[v] == 1 || !dfs(v, graph, dp)) {
                dp[src] = 3;
                return false;
            }
        }
        
        dp[src] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> dp(n, 0);
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            if(dfs(i, graph, dp)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
