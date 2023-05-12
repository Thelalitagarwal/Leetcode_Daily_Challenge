/*
Link to the " Solving Questions With Brainpower " Problem ==>> https://leetcode.com/problems/solving-questions-with-brainpower/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/F5xxOU2pySg

*/

class Solution {
public:
    long long find(vector<vector<int>>&ques,int n,int ind,vector<long long>&dp){
        if(ind>=n)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        long long choose=0;
        choose=max(ques[ind][0]+find(ques,n,ind+ques[ind][1]+1,dp),find(ques,n,ind+1,dp));
        return dp[ind] = choose;
    }
    long long mostPoints(vector<vector<int>>& questions) {

        int n=questions.size();
        vector<long long>dp(n,-1);
        return find(questions,n,0,dp);

    }
};