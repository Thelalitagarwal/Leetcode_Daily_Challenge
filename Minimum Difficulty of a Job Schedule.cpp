class Solution {
public:
    int n , maxVal = 1e7;
    int solve(vector<int>& jobs, int d , int index ,  vector<vector<int>> &dp){
        if(n==index && d==0)
            return 0; 
        if(n==index || d==0 || n-index<d)
            return maxVal; 
        if(dp[index][d]!=-1)
            return dp[index][d]; 
        int maxEle = 0 , ans = maxVal; 
        for(int i=index;i<n;i++){
            maxEle = max(maxEle, jobs[i]);
            ans = min(ans , maxEle + solve(jobs , d-1 , i+1 , dp));
        }
        return dp[index][d] =ans;
    }
    
    int minDifficulty(vector<int>& jobs, int d) {
        n = jobs.size();
        if(n<d)
            return -1; 
        vector<vector<int>> dp(n,vector<int>(d+1,-1));
        return solve(jobs , d , 0 , dp); 
    }
};