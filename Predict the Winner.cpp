/*
Link to the " Predict the Winner " Problem ==>> https://leetcode.com/problems/predict-the-winner/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/_qMuhtc5WLs

*/

class Solution {
public:
    int solve(vector<int>& nums,int i,int j, bool choose){

        if(i>j) 
            return 0;
        
        int ans=0;
        
        if(choose){
            ans=max(nums[i]+solve(nums,i+1,j,false),nums[j]+solve(nums,i,j-1,false));
        }
        else{
            ans=min(-nums[i]+solve(nums,i+1,j,true),-nums[j]+solve(nums,i,j-1,true));
        }
        return ans;
    }

    bool PredictTheWinner(vector<int>& nums) {

        bool choose=true;

        int n=nums.size();

        int score=solve(nums,0,n-1,choose);

        if(score>=0) 
            return true;
        return false;
    }
};