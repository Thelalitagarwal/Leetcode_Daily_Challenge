/*
Link to the " Minimize Maximum of Array " Problem ==>>  https://leetcode.com/problems/minimize-maximum-of-array/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/xDN7LSSmvDU

*/

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {

        long long mini = nums[0];
        long long sum =  nums[0];
        for (int i = 1; i<nums.size(); i++){
            sum += nums[i];
            if (nums[i] > mini){
                int x = sum/(i+1);
                if (x >= mini){
                    if (sum%(i+1))
                        mini = x+1;
                    else
                        mini =x;
                }
            }
        }
        return mini;
    }
};