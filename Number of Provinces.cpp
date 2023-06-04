/*
Link to the " Number of Provinces " Problem ==>> https://leetcode.com/problems/number-of-provinces/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/xaxdyPZaQGI

*/

class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int i, vector<int>& visited,int n){
        if(visited[i]==1) 
            return;
        visited[i] = 1;
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1) 
                dfs(isConnected,j,visited,n);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        vector<int> visited(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                ans++;
                dfs(isConnected,i,visited,n);
            }
        }
        return ans;
    }
};