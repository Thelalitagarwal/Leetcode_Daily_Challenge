/*
Link to the "Search in Rotated Sorted Array" Problem ==>> https://leetcode.com/problems/search-in-rotated-sorted-array/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/LXOvu7vgfNw

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();

        int i = 0;

        int j = n-1;

        while(i<j-1){
            int k = (i+j)/2;
            if (nums[i] <= nums[k]){
                if(target>=nums[i] && target <=nums[k]){

                    if (nums[k] == target) 
                        return k;
                    j=k;
                    while(i<j-1)
                    {
                        k = (i+j)/2;
                        if(nums[k]<=target)     
                            i=k;
                        else j = k;
                    }
                    if (nums[i] == target) 
                        return i;
                    else return -1;
                }
                else
                {
                    i=k;
                }

            }
            else if (nums[k] <= nums[j])
            {
                if(target>=nums[k] && target<=nums[j])
                {
                     if (nums[j] == target) 
                        return j;
                    i=k;
                    while(i<j-1)
                    {
                        k = (i+j)/2;
                        if(nums[k]<=target)  i=k;
                        else j = k;

                    }
                    if (nums[i] == target) return i;
                    else return -1;
               }
               else
               {
                    j=k;
               }

            }
        }
        if (nums[i] == target) return i;
        if (nums[j] == target) return j;
        else return -1;
    }
};