class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& preq, vector<vector<int>>& quer) {
        vector<bool> ans(quer.size(), false);
        vector<vector<bool>> edge(n, vector<bool>(n, false));

        for(auto e : preq) {
            edge[e[1]][e[0]] = true;
        }

        for(int i = 0; i < n; i++)  {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    if(edge[i][k] && edge[k][j]) {
                        edge[i][j] = true;
                    }
                }
            }
        }

        for(int i = 0; i < quer.size(); i++) {
            int u = quer[i][1];
            int v = quer[i][0];

            if(edge[u][v]) {
                ans[i] = true;
            }
        }

        return ans;
    }
};