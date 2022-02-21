/*
 * @lc app=leetcode id=1752 lang=cpp
 *
 * [1752] Check if Array Is Sorted and Rotated
 */

// @lc code=start
class Solution {
 public:
  bool check(vector<int>& nums) {
    int count = 0;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      if (nums[(i + 1) % size] < nums[i]) {
        count++;
        if (count >= 2) {
          return false;
        }
      }
    }
    return true;
  }
};
// @lc code=end
