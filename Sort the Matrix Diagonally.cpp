class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    unordered_map<int,priority_queue<int,vector<int>,greater<int>>> m;
    int row = mat.size();
    if(row == 0) return mat;
    int col = mat[0].size();
        
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            int k = i-j;
            m[k].push(mat[i][j]);
        }
    }

    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            int k = i-j;
            mat[i][j] = m[k].top();
            m[k].pop();
        }
    }
        
    return mat; 
    }
};