class Solution {
public:
    void preorder(TreeNode* root, vector<int>& ord) {
        if(root == NULL) {
            return ;
        }

        preorder(root->left, ord) ;
        ord.push_back(root->val) ;

        preorder(root->right, ord) ;
    }

    int minDiffInBST(TreeNode* root) {
        vector<int> ord ;

        preorder(root, ord) ;

        int ans = INT_MAX ;

        for(int i = 0 ; i < ord.size()-1 ; i++) {
            ans = min(ans, abs(ord[i]-ord[i+1])) ;
        }

        return ans ;
    }
};