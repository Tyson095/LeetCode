// Method-2 using DSU

class Solution {
private:
    int find(int x, vector<int>& par) {
        if(par[x] == x) {
            return x;
        }

        return par[x] = find(par[x], par);
    }

    void unionByRank(vector<int>& par, vector<int>& rank, int u, int v) {
        int parU = find(u, par);
        int parV = find(v, par);

        if(parU == parV) {
            return;
        }

        if(rank[parU] == rank[parV]) {
            par[parV] = parU;
            rank[parU]++;
        }else if(rank[parU] < rank[parV]) {
            par[parU] = parV;
        }else{
            par[parV] = parU;
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ans = 0;
        vector<int> par(n), rank(n, 0);

        for(int i = 0; i < n; i++) {
            par[i] = i;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j]) {
                    unionByRank(par, rank, i, j);
                }
            }
        }
        set<int> s;

        for(int i = 0; i < n; i++) {
            s.insert(find(i, par));
        }

        return s.size();
    }
};