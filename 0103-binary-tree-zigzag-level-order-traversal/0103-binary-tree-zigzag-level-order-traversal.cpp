/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) {
            return ans;
        }

        deque<TreeNode*> dq;
        dq.push_front(root);
        bool rev = true;

        while(!dq.empty()) {
            vector<int> curr;
            int currLevel = dq.size();

            for(int i = 0; i < currLevel; i++) {
                if(rev) {
                    auto node = dq.front();
                    dq.pop_front();

                    curr.push_back(node->val);

                    if(node->left) {
                        dq.push_back(node->left);
                    }

                    if(node->right) {
                        dq.push_back(node->right);
                    }
                }else {
                    auto node = dq.back();
                    dq.pop_back();

                    curr.push_back(node->val);

                    if(node->right) {
                        dq.push_front(node->right);
                    }

                    if(node->left) {
                        dq.push_front(node->left);
                    }

                }
            }

            rev = !rev;
            ans.push_back(curr);
        }
        
        return ans;
    }
};