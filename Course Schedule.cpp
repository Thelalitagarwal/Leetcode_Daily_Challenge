/*
Link to the " Course Schedule " Problem ==>> https://leetcode.com/problems/course-schedule/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/_3jYfuagVF0

*/

class Solution {
public:
    bool dfs(vector<int>adj[],vector<bool>&vis,int ind,vector<bool>&vissf){
        
        if(vissf[ind]) 
            return false;
        
        if(vis[ind]) 
            return true;
        
        vis[ind] = vissf[ind] = 1;

        for(auto node:adj[ind])
            if(!dfs(adj,vis,node,vissf))
                return false;
        
        vissf[ind] = 0;
        return true;
    }

    bool canFinish(int num, vector<vector<int>>& pre) {

        vector<int>adj[num];

        for(int i=0;i<pre.size();i++){
            adj[pre[i][0]].push_back(pre[i][1]);
        }

        vector<bool>vis(num,0),vissf(num,0);

        for(int i=0;i<num;i++){
            if(!vis[i] && !dfs(adj,vis,i,vissf))
                return false; 
        }

        return true;
    }
};