class Solution {
public:    
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
        int r = m - 1;
        int c = 0;
        while (r>=0 && c<n){
            if (mat[r][c] == target) return true;
            else if (mat[r][c] < target) c++;
            else r--;
        }
        return false;
    }
};

