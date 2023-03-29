/*
Link to the " Reducing Dishes " Problem ==>>  https://leetcode.com/problems/reducing-dishes/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/A-N1SXEOXr4

*/

class Solution {
public:
    int helper(vector< int> &nums, int i, int j, vector<vector<int>> &dp){

        if(i==nums.size()){
            return 0;
        }
        if(dp[i][j]!=-1) 
            return dp[i][j];
        int pick = j*nums[i] + helper(nums, i+1, j+1, dp);
        int notpick = helper(nums,i+1,j,dp);
        return dp[i][j] = max(pick,notpick);
    }

    int maxSatisfaction(vector<int>& sat) {

        int n = sat.size();
        sort(sat.begin(),sat.end());
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return helper(sat,0,1,dp);
    }
};