/*
Link to the "Unique Paths II" Problem ==>> https://leetcode.com/problems/unique-paths-ii/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/dcH_IcNqOAg

*/


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();

        int n = obstacleGrid[0].size();

        vector<vector<int>>dp(m, vector<int>(n));

        dp[0][0] = 1;

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
            return 0;
        }

        for (int i = 0; i < m; ++i) {

            for (int j = 0; j < n; ++j) {
                
                if (obstacleGrid[i][j] == 1) {
                    continue;
                }
                else {
                    if (i > 0) {
                        dp[i][j] +=dp[i-1][j];
                    }
                    if (j > 0) {
                        dp[i][j] +=dp[i][j-1];
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
};