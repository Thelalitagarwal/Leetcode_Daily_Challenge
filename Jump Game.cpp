class Solution {
public:
  bool canJump(vector<int> &nums) {
    int max_distance = 0;
    const int target = nums.size() - 1;
    for (int i = 0; i < nums.size() && i <= max_distance; ++i) {
      max_distance = std::max(max_distance, nums[i] + i);
    }
    return target <= max_distance;
  }
};