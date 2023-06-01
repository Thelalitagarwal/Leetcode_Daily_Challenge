/*
Link to the " Shortest Path in Binary Matrix " Problem ==>> https://leetcode.com/problems/shortest-path-in-binary-matrix/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/V5I7WTX4JrQ

*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0){
            return -1;
        }
        queue<pair<int,int>> q;
        q.push({0,0});
        int res = 0;
        while(!q.empty()){
            int m = q.size();
            for(int i=0; i<m; i++){
                auto [r,c] = q.front();
                q.pop();
                if(r<0 || r>=n || c<0 || c>=n || grid[r][c]==1 || visited[r][c]){
                    continue;
                }
                if(r==n-1 && c==n-1){
                    return res+1;
                }
                visited[r][c] = 1;
                q.push({r-1,c-1});
                q.push({r-1,c});
                q.push({r-1,c+1});
                q.push({r,c-1});
                q.push({r,c+1});
                q.push({r+1,c-1});
                q.push({r+1,c});
                q.push({r+1,c+1});
            }
            res++;   
        }
        return -1;
    }
};