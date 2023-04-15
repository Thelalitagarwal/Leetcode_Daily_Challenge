/*
Link to the " Maximum Value of K Coins From Piles " Problem ==>>  https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/zOG-NwqPtB0

*/

class Solution {
public:
     int solve(int i,vector<vector<int>>&p, int k,vector<vector<int>> &dp){

        if(i>=p.size() || k<=0) 
            return 0;     
        if(dp[i][k]!=-1)
            return dp[i][k];
        int fur = solve(i+1,p,k,dp);
        int cur=0;
        for(int idx=0;idx<p[i].size() && idx<k; idx++){
            cur += p[i][idx]; 
            fur = max(fur, cur+solve(i+1,p,k-idx-1,dp));
        }
        return dp[i][k]=fur;
    }
    
    int maxValueOfCoins(vector<vector<int>>& p, int k) {
        
        vector<vector<int>> dp(p.size(), vector<int>(k+1,-1));
        return solve(0,p,k,dp);
    }
};