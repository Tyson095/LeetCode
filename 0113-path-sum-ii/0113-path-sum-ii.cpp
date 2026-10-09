class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& curr, TreeNode* root, int targetSum) {
        if(!root) {
            return;
        }

        targetSum -= root->val;
        curr.push_back(root->val);

        if(!root->left && !root->right && targetSum == 0) {
            ans.push_back(curr);
            return;
        }

        helper(ans, curr, root->left, targetSum);
        if(root->left) curr.pop_back();
        helper(ans, curr, root->right, targetSum);
        if(root->right) curr.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(ans, curr, root, targetSum);

        return ans;
    }
};