class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return pathSum(root, sum, targetSum);
    }
    bool pathSum(TreeNode* node, int sum, int targetSum){
        if(node == NULL) return false;
        sum += node->val;
        if(node->left == NULL && node->right ==NULL && sum == targetSum)
            return true;
        if(pathSum(node->left, sum, targetSum) || pathSum(node->right, sum, targetSum))
            return true;
            return false;
        
    }
};