/*
Link to the " Fair Distribution of Cookies " Problem ==>> https://leetcode.com/problems/fair-distribution-of-cookies/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/T_2AOlGIvfg

*/

class Solution {
public:
    int solve(vector<int>&v,int i,vector<int>&a){

        if(i==v.size()){
            int ans=0;
            for(auto it : a)
                ans=max(ans,it);
            return ans;
        }

        int mn=INT_MAX;

        for(int j=0;j<a.size();j++){
            a[j]+=v[i];

            mn=min(mn,solve(v,i+1,a));

            a[j]-=v[i];
        }
        return mn;
    }


    int distributeCookies(vector<int>&v, int k) {

        int i,n=v.size();
        vector<int>a(k);

        return solve(v,0,a);
    }
};