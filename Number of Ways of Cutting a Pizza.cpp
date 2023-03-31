#define ll long long
const int M = 1e9+7;
class Solution {
public:
    int fun(vector<vector<int>> &vc , int ci , int cj ,  int cuts , vector<vector<vector<int>>> &dp){
        if(cuts==0){
            if(vc[ci][cj]>0) return 1;
            return 0;
        }
        if(dp[ci][cj][cuts] != -1) return dp[ci][cj][cuts];
        ll rows =0 , cols =0;
        for(int i = ci+1 ; i<vc.size()-1;i++){
            if(vc[i][cj]>=cuts && vc[ci][cj] - vc[i][cj]>0)
                rows = (rows + fun(vc,i,cj,cuts-1,dp))%M;
        }
        for(int j = cj+1 ; j<vc[0].size()-1;j++){
            if(vc[ci][j]>=cuts && vc[ci][cj] - vc[ci][j]>0)
                cols = (cols + fun(vc,ci,j,cuts-1,dp))%M;
        }
        return dp[ci][cj][cuts] = (rows + cols)%M;
    }

    int ways(vector<string>& pizza, int cuts) {
        int n = pizza.size();
        int m = pizza[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (m+1, vector<int>(cuts+1,-1)));
        vector<vector<int>> count_apple(n+1,vector<int> (m+1,0));
        for(int i = n-1; i>=0 ; i--){
            for(int j = m-1 ; j>=0 ; j--){
                count_apple[i][j] = count_apple[i+1][j] + count_apple[i][j+1] - count_apple[i+1][j+1] + int(pizza[i][j]=='A');
            }
        }
        ll ans = fun(count_apple,0,0,cuts-1,dp);
        return ans;
    }
};