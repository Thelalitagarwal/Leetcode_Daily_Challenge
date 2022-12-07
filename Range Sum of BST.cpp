/* 

Link to the "Distance of nearest cell having 1" Problem ==>>  https://leetcode.com/problems/range-sum-of-bst/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/rQuiUXvR7e0 
   
*/

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (root == nullptr) 
            return 0;
        return (root->val >= L && root->val <= R ? root->val : 0) +
            rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    }
};