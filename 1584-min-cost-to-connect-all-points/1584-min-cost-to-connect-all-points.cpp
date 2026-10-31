class Solution {
public:
    int dis(int i, int j, vector<vector<int>>& points) {
        return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        vector<bool> vis(n, false);

        priority_queue<pair<int , int> , vector<pair<int,int>> , greater<pair<int,int>> > pq ;
        pq.push({0, 0});

        while(pq.size() > 0) {
            auto curr = pq.top();
            pq.pop();

            int wt = curr.first;
            int node = curr.second;

            if(vis[node]) {
                continue;
            }

            vis[node] = true;

            for(int i = 0; i < n; i++) {
                if(!vis[i]) {
                    int d = dis(node, i, points);
                    pq.push({d, i});
                }
            }
            ans += wt;
        }
        return ans;
    }
};