/* 

Link to the "Distance of nearest cell having 1" Problem ==>>  https://leetcode.com/problems/leaf-similar-trees/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/eoEbu0TnF7Q 
   
*/

class Solution {
public:
    void inorder(TreeNode* root,vector<int>& x){
        if(root==NULL) return;
        inorder(root->left,x);
        if(!root->left && !root->right) x.push_back(root->val);
        inorder(root->right,x);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a,b;
        inorder(root1,a);
        inorder(root2,b);
        return a==b;
    }
};