/*
Link to the " Count Ways To Build Good Strings " Problem ==>> https://leetcode.com/problems/count-ways-to-build-good-strings/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/PEJ883NDE4A

*/

class Solution {
    int mod=1e9+7;
    int solve(int target,int one ,int zero,vector<int>&dp){

        if(target==0)
            return 1;

        if(target<0)
            return 0;
        
        if(dp[target]!=-1)
            return dp[target];
        
        long long sum;

        sum=solve(target-one,one,zero,dp)+solve(target-zero,one,zero,dp);
        
        return dp[target]=sum%mod;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {

        int ans=0;

        vector<int>dp(high+1,-1);

        for(int i=low;i<=high;i++){

            ans=((ans%mod)+solve(i,one,zero,dp))%mod;
        }
        return ans;
    }
};