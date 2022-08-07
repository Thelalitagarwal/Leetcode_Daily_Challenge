class Solution {
public:
    int MOD = 1e9+7;
    int dfs(int n, char l, vector<vector<int>>& dp) {
        if(n == 0) 
            return 1;
        
        if(dp[n][l] != -1) 
            return dp[n][l];
        
        int total = 0;
        if(l == 'a') {
            total = (total + dfs(n-1, 'e', dp)) % MOD ;
        } 
        else if(l == 'e') {
            total = (total + dfs(n-1, 'a', dp))% MOD;
            total = (total +  dfs(n-1, 'i', dp))% MOD;
        } 
        else if(l == 'i') {
            total = (total +  dfs(n-1, 'a', dp))% MOD;
            total = (total +  dfs(n-1, 'e', dp))% MOD;
            total = (total +  dfs(n-1, 'o', dp))% MOD;
            total = (total +  dfs(n-1, 'u', dp))% MOD;
        } 
        else if(l == 'o') {
            total = (total +  dfs(n-1, 'i', dp))% MOD;
            total = (total +  dfs(n-1, 'u', dp))% MOD;
        } 
        else if(l == 'u') {
            total = (total +  dfs(n-1, 'a', dp))% MOD;
        } 
        else {
            total = (total +  dfs(n-1, 'a', dp))% MOD;
            total = (total +  dfs(n-1, 'e', dp))% MOD;
            total = (total +  dfs(n-1, 'i', dp))% MOD;
            total = (total +  dfs(n-1, 'o', dp))% MOD;
            total = (total +  dfs(n-1, 'u', dp))% MOD;
        
        return dp[n][l] = total;
    }
    
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> memo(n+1, vector<int>(130, -1));
        return dfs(n, '.', memo);
    }
};