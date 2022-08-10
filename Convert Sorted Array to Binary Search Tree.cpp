class Solution {
public:
    
    TreeNode* helper(vector<int>& nums, int left, int right){
        if(left > right){
            return NULL;
        }
        int mid = (left + right) / 2;
        TreeNode* temp = new TreeNode(nums[mid]);
        temp->left = helper(nums, left, mid-1);
        temp->right = helper(nums, mid+1 , right);
        return temp;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
};