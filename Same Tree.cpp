/*
Link to the "Same Tree" Problem ==>>  https://leetcode.com/problems/same-tree 
   
Link to the complete Explaination Video ==>> https://youtu.be/D7ceKn0Oo8E 

*/

class Solution {
public:

    bool ans=true;
    
    void func(TreeNode* p,TreeNode* q){
        if(p && q){
            if(p->val!=q->val){
                ans=false;
            }
            func(p->left,q->left);
            func(p->right,q->right);
        }
        if(p!=NULL && q==NULL){
            ans=false;
        }
        if(p==NULL && q!=NULL){
            ans=false;
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        func(p,q);
        return ans;
    }
};