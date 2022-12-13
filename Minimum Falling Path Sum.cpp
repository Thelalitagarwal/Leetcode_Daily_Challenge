
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int sum =0;
        for (int i = A.size()-2; i>=0; --i){
            for (int j = 0; j < A[0].size(); ++j){
                if (j>0 && j <A[0].size()-1)
                    A[i][j] += min(A[i+1][j], min(A[i+1][j-1], A[i+1][j+1]));
                else if (j == 0)
                    A[i][j] += min(A[i+1][j], A[i+1][j+1]);
                else 
                    A[i][j] += min(A[i+1][j],A[i+1][j-1]);
            }
        }
        sum = A[0][0];
        for (int i=0; i <A[0].size(); ++i)
        if (sum > A[0][i])
            sum = A[0][i];
        return sum;
    }
};