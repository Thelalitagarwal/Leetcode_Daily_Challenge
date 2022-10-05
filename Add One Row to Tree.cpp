class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        queue<TreeNode*> q;
        if(depth==1){
            TreeNode* x= new TreeNode(val);
            TreeNode* y=root;
            root=x;
            root->left=y;
        }
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            depth--;
            if(depth==0){
                break;
            }
            while(size--){            
                TreeNode* cur=q.front();
                q.pop();
                if(depth==1){
                    if(cur->left){
                        TreeNode* x= new TreeNode(val);
                        TreeNode* y=cur->left;
                        cur->left=x;
                        x->left=y;
                        q.push(x);
                    }
                    else{
                        TreeNode* x= new TreeNode(val);
                        cur->left=x;
                        q.push(x);
                    }
                    if(cur->right){
                        TreeNode* x= new TreeNode(val);
                        TreeNode* y=cur->right;
                        cur->right=x;
                        x->right=y;
                        q.push(x);
                    }
                    else{
                        TreeNode* x= new TreeNode(val);
                        cur->right=x;
                        q.push(x);
                    }
                }
                else{
                    if(cur->left){
                        q.push(cur->left);
                    }
                    if(cur->right){
                        q.push(cur->right);
                    }
                }
            }
        }
        return root;
    }
};