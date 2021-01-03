/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int index = 0;
    for (auto num : nums) {
      if (num != 0) {
        nums[index++] = num;
      }
    }
    int len = nums.size();
    for (; index < len; index++) {
      nums[index] = 0;
    }
  }
};
// @lc code=end
