class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1));
        queue<vector<int>> q;
        q.push({0,0,0,k});
        while(!q.empty()){
            vector<int> t = q.front();
            q.pop();
            int x = t[0];
            int y = t[1];
            if(x<0 || x>=m || y<0 || y>=n)
                continue;
            if(x == m-1 && y == n-1)
                return t[2];
            if(grid[x][y] == 1){
                if(t[3] > 0)
                    t[3]--;
                else
                    continue;
            }
            if(visited[x][y]!=-1 && visited[x][y]>=t[3]){
                continue;
            }
            visited[x][y] = t[3];
            q.push({x+1, y, t[2]+1, t[3]});
            q.push({x-1, y, t[2]+1, t[3]});
            q.push({x, y+1, t[2]+1, t[3]});
            q.push({x, y-1, t[2]+1, t[3]});
        }
        return -1;
    }
};