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
    void helper(TreeNode* root, int temp, int& ans) {
        if(!root) {
            return;
        }

        temp = temp*10 + root->val;

        if(!root->left && !root->right) {
            ans += temp;
        }

        helper(root->left, temp, ans);
        helper(root->right, temp, ans);
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0;
        helper(root, 0, ans);

        return ans;
    }
};