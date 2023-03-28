/*
Link to the " Minimum Cost For Tickets " Problem ==>>  https://leetcode.com/problems/minimum-cost-for-tickets/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/A-N1SXEOXr4

*/

class Solution {
public:

    int mincostTickets(vector<int>& days, vector<int>& costs){

        int n=days.size();
        vector<int>dp(n+31,0);
        for(int i=n-1;i>=0;i--){
            int nextDay=0;
            nextDay=lower_bound(days.begin(),days.end(),days[i]+1)-days.begin();
            int op1= costs[0]+ dp[nextDay];
            nextDay= lower_bound(days.begin() , days.end() , days[i]+7)-days.begin();
            int op2= costs[1]+ dp[nextDay];
            nextDay= lower_bound(days.begin() , days.end() , days[i]+30)-days.begin();
            int op3= costs[2]+ dp[nextDay];  
            dp[i]=min(op1 , min( op2 , op3));
        }
        return dp[0];
    }
};