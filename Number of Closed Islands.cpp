/*
Link to the " Number of Closed Islands " Problem ==>>  https://leetcode.com/problems/number-of-closed-islands/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/bHZvZgmhy74

*/

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid){

        int dir_x[4] = {1, -1, 0, 0};
        int dir_y[4] = {0, 0, 1, -1};
        int ans = 0;  
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(vis[i][j] || grid[i][j] == 1) 
                    continue;
                queue<pair<int, int>> q({{i, j}});
                bool is_closed = true;
                while(!q.empty()){
                    auto front = q.front();
                    q.pop();
                    for(int k = 0; k < 4; k++){
                        int dy = front.first + dir_y[k];
                        int dx = front.second + dir_x[k];               
                        if(dy < 0 || dy >= m || dx < 0 || dx >= n) { 
                            is_closed = false;
                            continue;
                        }
                        if(grid[dy][dx] == 1) continue;
                        if(vis[dy][dx]) continue;
                        vis[dy][dx] = true;
                        q.push({dy, dx});
                    }
                }
                if(is_closed) 
                    ans++;
            }
        }
        return ans;
    }
};