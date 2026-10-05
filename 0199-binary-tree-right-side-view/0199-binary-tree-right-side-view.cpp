class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) {
            return ans;
        }

        deque<TreeNode*> dq;
        dq.push_back(root);

        while(dq.size() > 0) {
            int size = dq.size();
            auto curr = dq.back();
            ans.push_back(curr->val);

            for(int i = 0; i < size; i++) {
                auto x = dq.front();
                dq.pop_front();

                if(x->left) {
                    dq.push_back(x->left);
                }

                if(x->right) {
                    dq.push_back(x->right);
                }

            }
        }

        return ans;
    }
};