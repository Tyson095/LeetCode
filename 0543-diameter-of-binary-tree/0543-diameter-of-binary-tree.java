class Solution {
    int ans = 0 ;

    int helper(TreeNode root) {
        if(root == null) {
            return 0 ;
        }

        int left = helper(root.left) ;
        int right = helper(root.right) ;

        ans = Math.max(right+left, ans) ;

        return Math.max(right, left) +1 ;
    }

    public int diameterOfBinaryTree(TreeNode root) {
        helper(root) ;

        return ans ;     
    }
}