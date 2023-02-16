/*
Link to the "Maximum Depth of Binary Tree" Problem ==>>  https://leetcode.com/problems/maximum-depth-of-binary-tree/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/EVydX_Sn5Ow

*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) 
            return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }
};