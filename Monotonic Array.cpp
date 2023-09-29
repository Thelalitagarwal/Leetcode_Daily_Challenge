/*
Link to the "Monotonic Array" Problem ==>> https://leetcode.com/problems/monotonic-array/?envType=daily-question&envId=2023-09-29 
   
Link to the complete Explaination Video ==>> https://youtu.be/w0XVOR4taLY

*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        int left=0,right=nums.size()-1;

        while(left<right) {
            if(nums[left]%2==1) {
                while(right>left && nums[right]%2==1) {
                    right--;
                }
                swap(nums[left],nums[right]);
            }
            left++;
        }
        
        return nums;
    }
};