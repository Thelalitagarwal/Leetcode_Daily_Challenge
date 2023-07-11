/*
Link to the " All Nodes Distance K in Binary Tree " Problem ==>> https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/TIzJ1OXGt9g

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool flag=false;
    void check(TreeNode* root,TreeNode* target,unordered_map<TreeNode*,TreeNode*>&parent){

        if(root==nullptr)
            return ;
        if(root->val==target->val){
            flag=true;
        }
        parent[root->left]=root;
        parent[root->right]=root;
        check(root->left,target,parent);
        check(root->right,target,parent);
    }

    void solve(TreeNode*root,int k,vector<int>&ans,
    unordered_map<TreeNode*,TreeNode*>&   parent,unordered_map<TreeNode*,int>&main,int h)
    {

        if(root==nullptr)
            return ;
        if(main.find(root)!=main.end()){
            return;
        }
        main[root]=h+1;
        if(h==k){
            ans.push_back(root->val);
        }
        solve(root->left,k,ans,parent,main,h+1);
        solve(root->right,k,ans,parent,main,h+1);        
        solve(parent[root],k,ans,parent,main,main[root]);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*,TreeNode*>parent;
        unordered_map<TreeNode*,int>main;
        vector<int>ans;
        check(root ,target,parent);
        if(root==NULL || flag==false)
            return ans;
        solve(target,k,ans,parent,main,0);
        return ans;
    }
};