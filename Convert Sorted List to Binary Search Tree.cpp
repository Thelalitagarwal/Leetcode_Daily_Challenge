/*
Link to the " Convert Sorted List to Binary Search Tree " Problem ==>>  https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/mbEaJWHtTvQ

*/

class Solution {
public:
    TreeNode* chk(int i, int j, vector<int>& v){

        if(i>j){
            return NULL;
        }
        int mid=i+(j-i)/2;
        TreeNode* root=new TreeNode(v[mid]);
        root->left=chk(i, mid-1, v);
        root->right=chk(mid+1, j, v);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {

        vector<int>v;
        while(head){
            v.push_back(head->val);
            head=head->next;
        }
        int i=0, j=v.size();
        return chk(i, j-1, v);
    }
};