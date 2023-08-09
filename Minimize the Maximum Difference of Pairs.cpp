/*
Link to the "Minimize the Maximum Difference of Pairs" Problem ==>> https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/BQKF2XuengY

*/

class Solution {
public:
    int minimizeMax(std::vector<int>& nums, int p) {

        sort(nums.begin(), nums.end());

        int left = 0, right = nums.back() - nums.front(); 

        while (left < right) {

            int mid = (left + right) / 2;

            if (can_form_pairs(nums, mid, p)) {
                right = mid;
            } 
            else {
                left = mid + 1;
            }
        }
        return left;
    }
    
private:
    bool can_form_pairs(const vector<int>& nums, int mid, int p) {
        int count = 0;
        for (int i = 0; i < nums.size() - 1 && count < p;i++) {

            if (nums[i+1] - nums[i] <= mid) {
                count++;
                i++;
            }
        }
        return count >= p;
    }
};