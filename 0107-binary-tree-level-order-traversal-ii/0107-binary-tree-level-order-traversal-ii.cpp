class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int levelSize = q.size();
            vector<int> currLevel;

            for(int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                currLevel.push_back(node->val);

                if(node->left) {
                    q.push(node->left);
                    }
                if(node->right) {
                    q.push(node->right);
                }
            }

            ans.push_back(currLevel);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
