/*
Link to the "Minimum ASCII Delete Sum for Two Strings" Problem ==>> https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/J4YQL9fKOLc

*/

class Solution {
public:

    int solve(string& s1,string& s2,int i , int j,vector<vector<int>>& dp ){
        
        if(i<0 && j>=0){
            int ans =0;
            while(j>=0){
                ans+=s2[j--];
            }
            return ans;
        }
        else if(j<0 && i>=0){
            int ans=0;
            while(i>=0){
                ans+=s1[i--];
            }
            return ans;
        }
        else if(i<0 && j<0){
            return 0;
        }

        if(dp[i][j] != -1) 
            return dp[i][j];

        if(s1[i] == s2[j]){
           return dp[i][j] = solve(s1,s2,i-1,j-1,dp);
        }
        else{
            return dp[i][j] = min(solve(s1,s2,i-1,j,dp)+s1[i],solve(s1,s2,i,j-1,dp) + s2[j]);
        }
        
    }


    int minimumDeleteSum(string s1, string s2) {

        int n = s1.length();
        int m = s2.length();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        return solve(s1,s2,n-1,m-1,dp);

    }
};