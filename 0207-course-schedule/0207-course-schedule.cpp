class Solution {
public:
    bool isCycle(vector<vector<int>>& edges, int src, vector<int>& vis, vector<int>& recPath) {
        vis[src] = true ;
        recPath[src] = true ;

        for(int i = 0 ; i < edges.size() ; i++) {
            int u = edges[i][1] ;
            int v = edges[i][0] ;

            if(src == u) {
                if(!vis[v]) {
                    if(isCycle(edges, v, vis, recPath)) {
                        return true ;
                    }
                }else if(recPath[v]) {
                    return true ;
                }
            }
        }

        recPath[src] = false ;
        return false ;
    }

    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, false), recPath(n, false) ;

        for(int i = 0 ; i < n ; i++) {
            if(!vis[i]) {
                if(isCycle(edges, i, vis, recPath)) {
                    return false ;
                }
            }
        }

        return true ;
    }
};