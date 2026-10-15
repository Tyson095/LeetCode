class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n= courses.size();
        sort(courses.begin(),courses.end(), [](auto &a, auto &b){
    return a[1] < b[1];
});
        priority_queue<int>pq;
        int sum=0;
        for(int i=0;i<n ; i++){
            sum+=courses[i][0];
            pq.push(courses[i][0]);
            if (sum > courses[i][1]){
            sum-=pq.top();
            pq.pop();
            }
        }
       return pq.size();
    }
};