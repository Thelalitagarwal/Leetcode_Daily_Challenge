class Solution {
public:
    vector<int>rowDir = {-1, 1, 0, 0};
    vector<int>colDir = {0, 0, -1, 1};
    bool border(vector<vector<char>>&maze, int row, int col){
        if ((row == 0) || (row == maze.size() - 1)) return true;
        if ((col == 0) || (col == maze[0].size() - 1)) return true;
        return false;
    }
    bool ValStep(vector<vector<char>>&maze, int& row, int& col){
        int m = maze.size(), n = maze[0].size();
        if (row < 0 || row == m || col < 0 || col == n || maze[row][col] == '+') return false;
        else return true;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>>q;
        q.push({entrance[0], entrance[1]});
        int path = 0;
        maze[entrance[0]][entrance[1]] = '+'; 
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int row = q.front().first;
                int col = q.front().second;
                q.pop(); 
                for (int dir = 0; dir < 4; dir++) {
                    int newRow = row + rowDir[dir];  
                    int newCol = col + colDir[dir];  
                    if (ValStep(maze, newRow, newCol)) {
                        maze[newRow][newCol] = '+';
                        if (border(maze, newRow, newCol)) return (path + 1); 
                        else q.push({newRow, newCol});
                    }
                }
            }
            path++; 
        }
        return -1;
    }
};