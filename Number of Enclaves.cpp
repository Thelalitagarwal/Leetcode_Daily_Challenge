/*
Link to the " Number of Enclaves " Problem ==>>  https://leetcode.com/problems/number-of-enclaves/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/C4X7D19k3As

*/

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int dir_x[4] = {1, -1, 0, 0};
        int dir_y[4] = {0, 0, 1, -1};
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0 || vis[i][j]) 
                    continue;
                int cells = 0; 
                bool enclosed = true;   
                queue<pair<int, int>> q({{i, j}});
                vis[i][j] = true;
                while(!q.empty()){
                    auto front = q.front();
                    q.pop();
                    cells++;
                    for(int k = 0; k < 4; k++){
                        int dy = front.first + dir_y[k];
                        int dx = front.second + dir_x[k];
                        if(dx < 0 || dx >= n || dy < 0 || dy >= m) { 
                            enclosed = false;
                            continue;                            
                        }
                        if(vis[dy][dx]) continue;
                        if(grid[dy][dx] == 0) continue;
                        vis[dy][dx] = true;
                        q.push({dy, dx});
                    }
                }
                if(enclosed) 
                    ans += cells;
            }
        }
        return ans;
    }
};