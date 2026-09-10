class Solution {
public:
    int reqRoots = 0 ;

    pair<int, int> dfs(TreeNode* root) {
        if(!root) {
            return {0, 0} ;
        }

        auto [leftCount, leftSum] = dfs(root->left) ;
        auto [rightCount, rightSum] = dfs(root->right) ;

        int sum = leftSum + rightSum + root->val ;
        int n = leftCount + rightCount + 1 ;

        if(root->val == (sum/n)) {
            reqRoots++ ;
        }

        return {n, sum} ;
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root) ;
        return reqRoots ;
    }
};