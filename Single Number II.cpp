/*
Link to the " Buddy Strings " Problem ==>> https://leetcode.com/problems/buddy-strings/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/v2FWcP-QGqo

*/


class Solution {
public:
    int singleNumber(vector<int>& nums) {

        if(nums.size()<3) 
            return nums[0];

        sort(nums.begin(), nums.end());

        if(nums[0] != nums[1]) 
            return nums[0];

        for(int i=1; i<nums.size()-1; i++) {
            if(nums[i-1] != nums[i] && nums[i] != nums[i+1])
                return nums[i];
        }

        return nums[nums.size()-1];
    }
};