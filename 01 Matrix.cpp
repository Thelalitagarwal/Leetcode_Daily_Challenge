/*
Link to the " 01 Matrix " Problem ==>>  https://leetcode.com/problems/01-matrix/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/mlfJ7YpaPJM

*/

class Solution {
public:
    vector<int> DIR = {0, 1, 0, -1, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        queue<pair<int, int>> q;

        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                if (mat[r][c] == 0) 
                    q.push({r, c});
                else mat[r][c] = -1;

        while (!q.empty()) {
            auto [r, c] = q.front(); 
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nr = r + DIR[i], nc = c + DIR[i+1];
                if (nr < 0 || nr == m || nc < 0 || nc == n || mat[nr][nc] != -1) 
                    continue;
                
                mat[nr][nc] = mat[r][c] + 1;
                q.push({nr, nc});
            }
        }
        return mat;
    }
};
