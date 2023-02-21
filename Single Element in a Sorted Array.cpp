/*
Link to the "Single Element in a Sorted Array" Problem ==>>  https://leetcode.com/problems/single-element-in-a-sorted-array/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/ANyr7n8uHrM

*/

class Solution {
public:

    int func(vector<int> nums, int low,int high){

        int mid=(low+high)/2;
        if(low==high){
            return low;
        }
        if(mid%2==0 && nums[mid]==nums[mid+1]){
            return func(nums,mid+1,high);
        }
        else if(mid%2==0 && nums[mid]!=nums[mid+1]){
            return func(nums,low,mid);
        }
        else if(mid%2!=0 && nums[mid]==nums[mid-1]){
            return func(nums,mid+1,high);
        }
        return func(nums,low,mid);
    }

    int singleNonDuplicate(vector<int>& nums) {

        if(nums.size()==1){
            return nums[0];
        }
        int index= func(nums,0,nums.size()-1);
        return nums[index];
    }
};