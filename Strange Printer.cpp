/*
Link to the "Strange Printer" Problem ==>> https://leetcode.com/problems/strange-printer/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/uEC3oT_WvjQ

*/


class Solution {
public:
    int dp[102][102];

    int f(int i,int j,string& s){

        if(i>j)
        return 0;

        if(dp[i][j]!=-1) 
            return dp[i][j];
        
        int ans=INT_MAX;

        for(int k=i;k<=j;k++){

            int res=0;

            int st=k;

            while(s[k]==s[st])
                k++;

            if(st>i) 
                res+=f(i,st-1,s);

            if(k<=j) 
                res+=f(k,j,s);

            if(s[st]!=s[i-1]) 
                res++;
                
            k--;
            ans=min(ans,res);
        }
        return dp[i][j]=ans;
    }
    int strangePrinter(string s) {

        memset(dp,-1,sizeof(dp));

        int n=s.size();

        s.insert(s.begin(),'0');

        s+='0';

        return f(1,n,s);
    }
};