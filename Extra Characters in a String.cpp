/*
Link to the "  Extra Characters in a String " Problem ==>> https://leetcode.com/problems/extra-characters-in-a-string/description/?envType=daily-question&envId=2023-09-02 
   
Link to the complete Explaination Video ==>> https://youtu.be/eDm3DHBgECc

*/

class Solution {
public:
    vector<int> dp;
    int n;
    int f(int i, string& s, vector<string>& dictionary) {

        if (i == n)     
            return 0;

        if (dp[i]!= -1) 
            return dp[i]; 

        int ans = n; 

        for (string& w : dictionary) {
            int wLen = w.size();
            if (i+wLen <= s.size() && s.substr(i, wLen) == w) {
                int extra = f(i+wLen, s, dictionary);
                ans = min(ans, extra);
            }
        }
        
        int noWord = 1 + f(i+1, s, dictionary);
        ans = min(ans, noWord);
        return dp[i]=ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {

        n=s.size();
        dp.assign(n, -1); 
        return f(0, s, dictionary);
    }

};