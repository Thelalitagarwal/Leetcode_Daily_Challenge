/*
Link to the "Validate Binary Tree Nodes" Problem ==>> https://leetcode.com/problems/validate-binary-tree-nodes/
   
Link to the complete Explaination Video ==>> https://youtu.be/PwiEoTPYzBU

*/

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int cnt = n-1;
        vector<int> par(n, -1);
        vector<int> vis(n, 0);

        for(int i=0;i<n;i++){

            if(leftChild[i] == -1)
                continue;
            
            if(vis[leftChild[i]] == 1) 
                return false;
            
            int temp = par[i];

            while(temp != -1){
                if(temp == leftChild[i])
                    return false;
                temp = par[temp];
            }

            par[leftChild[i]] = i;

            vis[leftChild[i]] = 1;

            cnt--;
        }

        for(int i=0;i<n;i++){

            if(rightChild[i] == -1)
                continue;
            
            if(vis[rightChild[i]] == 1) 
                return false;
            
            int temp = par[i];

            while(temp != -1){
                if(temp == rightChild[i])
                    return false;
                temp = par[temp];
            }

            par[rightChild[i]] = i;

            vis[rightChild[i]] = 1;

            cnt--;

        }
        
        if(cnt != 0)
            return false;
        return true;
    }
};