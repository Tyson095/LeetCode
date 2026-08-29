class Solution {
public:
    void helper(vector<int>& candidates, vector<int>& temp, vector<vector<int>>& ans, int target, int idx) {
        if(target < 0 || idx >= candidates.size()) {
            return ;
        }else if(target == 0) {
            ans.push_back(temp) ;
            return ;
        }

        temp.push_back(candidates[idx]) ;
        helper(candidates, temp, ans, target-candidates[idx], idx) ;

        //helper(candidates, temp, ans, target-candidates[idx], idx+1) ;

        temp.pop_back() ;
        helper(candidates, temp, ans, target, idx+1) ;
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp ;
        vector<vector<int>> ans ;

        helper(candidates, temp, ans, target, 0) ;

        return ans ;
    }
};