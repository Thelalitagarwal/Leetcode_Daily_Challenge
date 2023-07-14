/*
Link to the " Longest Arithmetic Subsequence of Given Difference " Problem ==>> https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/9BqVjYVLSMU

*/

class Solution {
public:
    int longestSubsequence(vector<int>& nums, int diff) {
        int n=nums.size();

        unordered_map<int,int> mp;

        int ans=1;

        for(auto x:nums){
            
            if(mp.count(x-diff)){
                mp[x]=mp[x-diff]+1;
            }
            else{
                mp[x]=1;
            }
            ans=max(ans,mp[x]);
        }
        return ans;
    }
};