class Solution {
public:
    vector<vector<int>> res; 
    vector<int> curr;
    void dfs(TreeNode* root, int curr_sum, int target_sum){
        if(root == NULL)
            return;
        curr.push_back(root -> val);
        curr_sum += root -> val;
        if(root -> left == NULL && root -> right == NULL){
            if(curr_sum == target_sum){
                res.push_back(curr);
            }
        }
        dfs(root -> left, curr_sum, target_sum);
        dfs(root -> right, curr_sum, target_sum);
        curr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {   
        dfs(root, 0, targetSum);
        return res;
    }
};