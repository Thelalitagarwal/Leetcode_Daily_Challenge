/*
Link to the "Find Mode in Binary Search Tree" Problem ==>> https://leetcode.com/problems/find-mode-in-binary-search-tree/description/?envType=daily-question&envId=2023-11-01
   
Link to the complete Explaination Video ==>> https://youtu.be/bPRmhKdDnpY

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
    unordered_map<int, int> umap;
    void inorder(TreeNode* root){
        if(root){
            inorder(root->left);
            umap[root->val]++;
            inorder(root->right);
        }
    }
    vector<int> findMode(TreeNode* root) {

        inorder(root);

        vector<int> res;

        int max_count = -1;
        
        for(auto a : umap)
            if(a.second > max_count)
                max_count = a.second;
            
        for(auto a : umap)
            if(max_count == a.second)
                res.push_back(a.first);
            
        return res;
        
    }
};