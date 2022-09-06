class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        
        if(!root) return NULL;
        
        TreeNode *left=pruneTree(root->left);
        TreeNode *right=pruneTree(root->right);
        
        if(root->val==0 and !left and !right) return NULL;
        
        root->left=left;
        root->right=right;
        return root;
        
    }
};