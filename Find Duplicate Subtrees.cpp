/*
Link to the "Find Duplicate Subtrees
" Problem ==>>  https://leetcode.com/problems/find-duplicate-subtrees/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/2OBDP3Omi30

*/

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

        unordered_map<string,int>a;
        vector<TreeNode*>ans;
        solve(root,a,ans);
        return ans;
    }
    string solve(TreeNode* root,unordered_map<string,int>&a,vector<TreeNode*>&ans){
        if(!root){
            return "";
        }
        string s=to_string(root->val)+","+solve(root->left,a,ans)+","+solve(root->right,a,ans);
        a[s]++;
        if(a[s]==2){
            ans.push_back(root);
        }
        return s;
    }
};