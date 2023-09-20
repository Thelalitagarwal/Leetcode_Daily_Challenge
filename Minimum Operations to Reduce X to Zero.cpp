class Solution {
public:
    int minOperations(vector<int>& nums, int targetSum) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int target = totalSum - targetSum;
        if (target < 0)
            return -1;
        if (target == 0)
            return nums.size();
        int n = nums.size();
        int minOperations = INT_MAX;
        int currentSum = 0;
        int leftIndex = 0, rightIndex = 0;
        while (rightIndex < n) {
            currentSum += nums[rightIndex];
            rightIndex++;
            while (currentSum > target && leftIndex < n) {
                currentSum -= nums[leftIndex];
                leftIndex++;
            }
            if (currentSum == target)
                minOperations = min(minOperations, n - (rightIndex - leftIndex));
        }
        return (minOperations == INT_MAX) ? -1 : minOperations;
    }
};