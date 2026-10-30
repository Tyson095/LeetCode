class Solution {
public:
    struct State {
        int cost, node, run;
        bool operator>(const State& other) const {
            return cost > other.cost;
        }
    };

    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));

        priority_queue<State, vector<State>, greater<State>> pq;
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while(!pq.empty()) {
            State cur = pq.top();
            pq.pop();

            if(cur.cost > dist[cur.node][cur.run]) {
                continue;
            }
            if(cur.node == n - 1) {
                return cur.cost;
            }

            for(auto& [v, w] : adj[cur.node]) {
                int newRun = (labels[v] == labels[cur.node]) ? cur.run + 1 : 1;
                if(newRun > k) {
                    continue;
                }

                int newCost = cur.cost + w;
                if(newCost < dist[v][newRun]) {
                    dist[v][newRun] = newCost;
                    pq.push({newCost, v, newRun});
                }
            }
        }
        
        return -1;
    }
};