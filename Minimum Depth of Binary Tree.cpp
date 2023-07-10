/*
Link to the " Minimum Depth of Binary Tree " Problem ==>> https://leetcode.com/problems/minimum-depth-of-binary-tree/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/BNU_3wZ29Q8

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {

        if(root==NULL){
            return 0;
        }

        int leftt=minDepth(root->left);

        int rightt=minDepth(root->right);
        
        if(min(leftt,rightt)!=0){
            return min(leftt,rightt)+1;
        }
        else{
            return max(leftt,rightt)+1;
        }
    }
};