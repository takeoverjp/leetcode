/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int count = 0;
    for (auto it = nums.begin(); it != nums.end();) {
      if (*it == 0) {
        it = nums.erase(it);
        count++;
        continue;
      }
      it++;
    }

    for (int i = 0; i < count; i++) {
      nums.push_back(0);
    }
  }
};
// @lc code=end
