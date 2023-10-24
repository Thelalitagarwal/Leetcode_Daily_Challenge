/*
Link to the "Find Largest Value in Each Tree Row" Problem ==>> https://leetcode.com/problems/find-largest-value-in-each-tree-row/?envType=daily-question&envId=2023-10-24
   
Link to the complete Explaination Video ==>> https://youtu.be/h96MLBgs8Rg

*/

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {

        vector<int> ans;

        if(root == NULL) 
            return ans;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){

            int size = q.size();

            int maxi = INT_MIN;

            for(int i=0; i<size; i++){
                TreeNode* front = q.front();
                q.pop();
                maxi = max(maxi, front -> val);
                if(front -> left) 
                    q.push(front -> left);
                if(front -> right) 
                    q.push(front -> right);
            }
            ans.push_back(maxi);
        }
        
        return ans;
    }
};