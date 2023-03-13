/*
Link to the " Symmetric Tree " Problem ==>>  https://leetcode.com/problems/symmetric-tree/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/lGxQfZ1mujc

*/

class Solution {
public:
    bool helper(TreeNode* left,TreeNode* right){

        if(!left and !right)
            return true;
        if((left != NULL and right == NULL) || (left == NULL and right != NULL) || (left->val!=right->val))
            return false;
        if(left->val==right->val)
            return helper(left->right,right->left) && helper(left->left,right->right);
        return true;
    }
    
    bool isSymmetric(TreeNode* root) {

        if(!root)
            return true;
        return helper(root->left,root->right);
    }
};