/*
Link to the " Minimum Size Subarray Sum " Problem ==>> https://leetcode.com/problems/minimum-size-subarray-sum/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/jA7IxWg8uTA

*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n=nums.size();
        int wsum=0, l=0, r;
        int ans=INT_MAX;
        for(r=0; r<n; r++){
            wsum+=nums[r];
            while(wsum>=target){
                ans=min(ans, r-l+1);       
                wsum-=nums[l];  
                l++;
            }
        }
        return ans==INT_MAX? 0: ans;
    }
};