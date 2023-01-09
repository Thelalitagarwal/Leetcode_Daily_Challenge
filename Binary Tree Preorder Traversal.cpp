/*
Link to the "Binary Tree Preorder Traversal" Problem ==>>  https://leetcode.com/problems/binary-tree-preorder-traversal/description/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/1XHKNPDFo7Q 

*/

class Solution {
public:
    vector<int> ans;

    void fun(TreeNode* root){
        if(root){
            ans.push_back(root->val);
            fun(root->left);
            fun(root->right);
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {

        fun(root);
        return ans;
    }
};
