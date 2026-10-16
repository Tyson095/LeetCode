class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n <= 2) {
            vector<int> res;
            for(int i = 0; i < n; i++) {
                res.push_back(i);
            }
            return res;
        }

        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);
        for(auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }

        queue<int> leaves;
        for(int i = 0; i < n; i++) {
            if(degree[i] == 1) {
                leaves.push(i);
            }
        }

        int remaining = n;
        while(remaining > 2) {
            int size = leaves.size();
            remaining -= size;
            for(int i = 0; i < size; i++) {
                int leaf = leaves.front();
                leaves.pop();
                for(int nb : graph[leaf]) {
                    if(--degree[nb] == 1) {
                        leaves.push(nb);
                    }
                }
            }
        }

        vector<int> res;
        while(!leaves.empty()) {
            res.push_back(leaves.front());
            leaves.pop();
        }

        return res;
    }
};