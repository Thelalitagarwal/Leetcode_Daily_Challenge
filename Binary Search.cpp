/*
Link to the " Binary Search " Problem ==>>  https://leetcode.com/problems/binary-search/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/8AUsxW6cu-Q

*/

class Solution {
public:
    
    int func(int low,int high,vector<int> nums,int target){

        int mid=(low+high)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(low==high){
            return -1;
        }
        else if(nums[mid]>target){
            return func(low,mid,nums,target);
        }
        else{
            return func(mid+1,high,nums,target);
        }
        return -1;
    }

    
    int search(vector<int>& nums, int target) {

        return func(0,nums.size()-1,nums,target);
    }
};