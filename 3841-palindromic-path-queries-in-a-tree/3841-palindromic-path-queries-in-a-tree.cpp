class Solution {
private:
    int timer;
    int LOGN;
    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> depth;
    vector<int> tin;
    vector<int> tout;
    vector<int> BIT;

    // DFS to perform Euler Tour and initialize Binary Lifting for LCA
    void dfs(int node, int parent, int d) {
        depth[node] = d;
        up[node][0] = parent;
        for (int i = 1; i < LOGN; ++i) {
            up[node][i] = up[up[node][i - 1]][i - 1];
        }

        tin[node] = ++timer;

        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, d + 1);
            }
        }

        tout[node] = ++timer;
    }

    // Binary Lifting to find the Lowest Common Ancestor (LCA)
    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        
        int diff = depth[u] - depth[v];
        for (int i = 0; i < LOGN; ++i) {
            if ((diff >> i) & 1) {
                u = up[u][i];
            }
        }
        
        if (u == v) return u;
        
        for (int i = LOGN - 1; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

    // Fenwick Tree (BIT) operations
    void bit_update(int idx, int val, int limit) {
        for (; idx < limit; idx += idx & (-idx)) {
            BIT[idx] ^= val;
        }
    }

    int bit_query(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & (-idx)) {
            res ^= BIT[idx];
        }
        return res;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        // Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // Initialize tree structures
        adj.assign(n, vector<int>());
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Determine log size for binary lifting
        LOGN = 0;
        while ((1 << LOGN) <= n) LOGN++;
        LOGN++; // Safely add one more level

        up.assign(n, vector<int>(LOGN, 0));
        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        timer = 0;

        // Run pre-processing DFS from root node 0
        dfs(0, 0, 0);

        int bit_limit = timer + 2;
        BIT.assign(bit_limit, 0);

        // Precompute bitmasks representing character parities
        vector<int> node_masks(n);
        for (int i = 0; i < n; ++i) {
            node_masks[i] = 1 << (s[i] - 'a');
            bit_update(tin[i], node_masks[i], bit_limit);
            bit_update(tout[i], node_masks[i], bit_limit);
        }

        vector<bool> answer;

        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;

            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;

                int old_mask = node_masks[u];
                int new_mask = 1 << (c - 'a');
                int change = old_mask ^ new_mask;

                // Update BIT positions to reflect changed character
                bit_update(tin[u], change, bit_limit);
                bit_update(tout[u], change, bit_limit);
                
                node_masks[u] = new_mask;

            } else if (type == "query") {
                int u, v;
                ss >> u >> v;

                int lca = get_lca(u, v);

                // Compute prefix path-XOR up to nodes
                int mask_u = bit_query(tin[u]);
                int mask_v = bit_query(tin[v]);
                int mask_lca = node_masks[lca];

                int path_mask = mask_u ^ mask_v ^ mask_lca;

                // An arrangement is a palindrome if at most one bit remains odd (set to 1)
                bool is_palindrome = (path_mask & (path_mask - 1)) == 0;
                answer.push_back(is_palindrome);
            }
        }

        return answer;
    }
};
