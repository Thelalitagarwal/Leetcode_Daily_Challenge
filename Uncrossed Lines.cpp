/*
Link to the " Uncrossed Lines " Problem ==>> https://leetcode.com/problems/uncrossed-lines/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/m052wX6wl54

*/

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {

        int n=nums1.size(),m=nums2.size();
        int dp[max(n+1,m+1)][max(n+1,m+1)];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<=max(n,m);i++){
            dp[0][i]=0;
            dp[i][0]=0;
        }
        for(int i=1;i<=nums1.size();i++){
            for(int j=1;j<=nums2.size();j++){
            if(nums1[i-1]==nums2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
          }
        }
        return dp[n][m];
    }
};