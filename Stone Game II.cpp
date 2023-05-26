/*
Link to the " Stone Game II " Problem ==>> https://leetcode.com/problems/stone-game-ii/ 
   
Link to the complete Explaination Video ==>>https://youtu.be/3y-NPO5uwsM

*/

class Solution {
public:
    int stoneGameII(vector<int>& piles) {

        int n = piles.size();
        vector<int> suffixSums(n + 1);
        suffixSums[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixSums[i] = suffixSums[i + 1] + piles[i];
        }
        vector<vector<int>> dp(n, vector<int>(n + 1));
        for (int i = n - 1; i >= 0; i--) {
            for (int m = 1; m <= n; m++) {
                if (i + 2 * m >= n) {
                    dp[i][m] = suffixSums[i];
                } 
                else {
                    for (int x = 1; x <= 2 * m; x++) {
                        int opponentScore = dp[i + x][max(x, m)];
                        int score = suffixSums[i] - opponentScore;
                        dp[i][m] = max(dp[i][m], score);
                    }
                }
            }
        }
        return dp[0][1];
    }
};