/*
Link to the "Coin Change II" Problem ==>> https://leetcode.com/problems/coin-change-ii/  
   
Link to the complete Explaination Video ==>> https://youtu.be/rjtoF2o5mt0

*/


class Solution {
public:
    int change(int amount, vector<int>& coins) {

        vector<int> dp(amount+1, 0);

        dp[0]=1;

        for(int c:coins){

            for(int i=c; i<=amount; i++)

                    dp[i]+=dp[i-c];

        }
        return dp[amount]; 
    }
};