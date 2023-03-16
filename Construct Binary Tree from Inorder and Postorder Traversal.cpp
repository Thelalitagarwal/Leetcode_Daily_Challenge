/*
Link to the " Construct Binary Tree from Inorder and Postorder Traversal " Problem ==>>  https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/7Z6ivS-TA3k

*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if (inorder.size() == 0 || postorder.size() == 0) {
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder.back());
        if (postorder.size() == 1) {
            return root;
        }
        
auto root_idx = find(begin(inorder), end(inorder), postorder.back()) - inorder.begin();
        
        vector<int> left_inorder(inorder.begin(), inorder.begin() + root_idx);
        vector<int> right_inorder(inorder.begin() + root_idx + 1, inorder.end());
        vector<int> left_postorder(postorder.begin(), postorder.begin() + root_idx);
        vector<int> right_postorder(postorder.begin() + root_idx, postorder.end() - 1);
        
        root->left = buildTree(left_inorder, left_postorder);
        root->right = buildTree(right_inorder, right_postorder);

        return root;      
    }
};