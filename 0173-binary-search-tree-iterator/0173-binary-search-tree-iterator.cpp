class BSTIterator {
public:
    stack<TreeNode* > s ;

    void pushAll(TreeNode* root) {
        while(root) {
            s.push(root) ;
            root = root->left ;
        }
    }

    BSTIterator(TreeNode* root) {
        pushAll(root) ;
    }
    
    int next() {
        TreeNode* temp = s.top() ;
        s.pop() ;
        pushAll(temp->right) ;
        return temp->val ;
    }
    
    bool hasNext() {
        return !s.empty() ;
    }
};