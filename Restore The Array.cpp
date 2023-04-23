/*
Link to the " Restore The Array " Problem ==>>  https://leetcode.com/problems/restore-the-array/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/yUaouOG2K_4

*/

class Solution {
public:
    int numberOfArrays(string s, int k) {

        vector<int> dp(s.size(), -1);
        return dfs(s, k, 0, dp);
    }
    int dfs(const string& s, long k, int i, vector<int>& dp) {

        if (i == s.size()) 
            return 1;
        if (s[i] == '0') 
            return 0;
        if (dp[i] != -1) 
            return dp[i];
        int ans = 0;
        long num = 0;
        for (int j = i; j < s.size(); j++) {
            num = num * 10 + s[j]-'0';
            if (num > k) 
                break; 
            ans += dfs(s, k, j + 1, dp);
            ans %= 1000000007;
        }
        return dp[i] = ans;
    }
};