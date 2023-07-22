/*
Link to the " Knight Probability in Chessboard " Problem ==>> https://leetcode.com/problems/knight-probability-in-chessboard/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/LAdtc498Q_I

*/

class Solution {
public:
    double findProb(int i,int j,int n,int k,vector<vector<vector<double>>>&dp){
        if(i<0 || j<0 || i>=n || j>=n) 
            return 0;

        if(k==0) 
            return 1;
        
        if(dp[i][j][k]!=-1) 
            return dp[i][j][k];
        
        vector<int>di{-2,-2,-1,-1,1,1,2,2};
        vector<int>dj{-1,1,-2,2,-2,2,-1,1};

        double ans=0;

        for(int r=0;r<8;r++){
                int x=i+di[r];
                int y=j+dj[r];
            ans+=findProb(x,y,n,k-1,dp);
        }
        
        return dp[i][j][k]=0.125*ans;
    }

    double knightProbability(int n, int k, int row, int column) {

        vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));

        return findProb(row,column,n,k,dp);
    }
};