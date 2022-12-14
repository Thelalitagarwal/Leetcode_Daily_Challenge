/*
Link to the "House Robber" Problem ==>>  https://leetcode.com/problems/house-robber/description/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/78AW9ZrOXnE 

*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
         dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1){
                pick+=dp[i-2];
            }
            dp[i]=max(pick,dp[i-1]);
        }
        return dp[n-1];
    }
};