class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        vector<int> ans(m);

        using T = pair<long, pair<int, int>>;
        using p = pair<int, int>;
        
        priority_queue<p, vector<p>, greater<p> > freeServers;     //  {server_weight, org_index}
        priority_queue<T, vector<T>, greater<T> > busy;            //  {time, {server_weight, org_index}}

        for(int i = 0; i < n; i++) {
            freeServers.push({servers[i], i});
        }

        long long t = 0;
        for(int j = 0; j < m; j++) {
            t = max(t, (long long)j);
            while(busy.size() > 0 && busy.top().first <= t) {
                auto x = busy.top();
                busy.pop();

                freeServers.push(x.second);
            }

            if(freeServers.size() == 0) {
                t = busy.top().first;
                while(busy.size() > 0 && busy.top().first <= t) {
                    auto x = busy.top();
                    busy.pop();

                    freeServers.push(x.second);
                }   
            }

            auto curr = freeServers.top();
            freeServers.pop();
            ans[j] = curr.second;
            busy.push({t + (long long)tasks[j], curr});
        }

        return ans;
    }
};