// 2 Approaches Are There For the Same Question


// 1 Approach

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)
            return;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* t=s.top();
            s.pop();
            if(t->right){
                s.push(t->right);
            }
            if(t->left){
                s.push(t->left);
            }
            if(!s.empty()){
                t->right=s.top();
            }
            t->left=NULL;
        }
    }
};



// 2 Approach

class Solution {
public:
    
    TreeNode* head;
    
    void preorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        preorder(root->right);
        preorder(root->left);
        root->right=head;
        root->left=NULL;
        head=root;
    } 
    
    void flatten(TreeNode* root) {
        head = NULL;
        preorder(root);
    }
};