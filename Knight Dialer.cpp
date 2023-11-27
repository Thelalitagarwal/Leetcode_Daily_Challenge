/*
Link to the "Knight Dialer" Problem ==>> https://leetcode.com/problems/knight-dialer/description/?envType=daily-question&envId=2023-11-27
   
Link to the complete Explaination Video ==>> https://youtu.be/WVokLqrfLUc

*/

class Solution {
public:
    int knightDialer(int n) {

      int kNum = 1000000007;

      long long dp[10][5001];

      for (int i = 0; i < 10; ++i) {
        dp[i][1] = 1;
      }

      for (int i = 2; i <= n; ++i) {
        dp[1][i] = (dp[6][i - 1] + dp[8][i - 1]) % kNum;
        dp[3][i] = (dp[4][i - 1] + dp[8][i - 1]) % kNum;
        dp[2][i] = (dp[7][i - 1] + dp[9][i - 1]) % kNum;
        dp[4][i] = (dp[3][i - 1] + dp[9][i - 1] + dp[0][i - 1]) % kNum;
        dp[5][i] = 0;
        dp[6][i] = (dp[1][i - 1] + dp[7][i - 1] + dp[0][i - 1]) % kNum;
        dp[7][i] = (dp[2][i - 1] + dp[6][i - 1]) % kNum;
        dp[8][i] = (dp[1][i - 1] + dp[3][i - 1]) % kNum;
        dp[9][i] = (dp[2][i - 1] + dp[4][i - 1]) % kNum;
        dp[0][i] = (dp[6][i - 1] + dp[4][i - 1]) % kNum;
      }

      int ans = 0;
      
      for (int i = 0; i < 10; ++i) {
        ans = (ans + dp[i][n]) % kNum;
      }
      return ans;
    }
};