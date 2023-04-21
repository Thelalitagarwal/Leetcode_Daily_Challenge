/*
Link to the " Profitable Schemes " Problem ==>>  https://leetcode.com/problems/profitable-schemes/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/MZdv_NQSS6w

*/

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {

        int MOD = 1e9 + 7;
        int size = group.size();
        vector<vector<vector<int>>> dp(size + 1, vector<vector<int>>(minProfit + 1, vector<int>(n + 1, 0)));
        dp[0][0][0] = 1;
        for (int i = 1; i <= size; i++) {
            int g = group[i - 1];
            int p = profit[i - 1];
            for (int j = 0; j <= minProfit; j++) {
                for (int k = 0; k <= n; k++) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (k >= g) {dp[i][j][k] = (dp[i][j][k] + dp[i - 1][max(0, j - p)][k - g]) % MOD;
                    }
                }
            }
        }
        int ans = 0;
        for (int k = 0; k <= n; k++) {
            ans = (ans + dp[size][minProfit][k]) % MOD;
        }
        return ans;
    }
};
