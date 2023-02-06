/*
Link to the "Shuffle the Array" Problem ==>>  https://leetcode.com/problems/shuffle-the-array/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/3kpxsfuQwJo

*/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(nums[i]);
            if(i+n<nums.size()){
                ans.push_back(nums[i+n]); 
            }
        }
        return ans;
    }
};