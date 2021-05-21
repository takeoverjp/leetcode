/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */

// @lc code=start
class Solution {
 public:
  vector<int> sortArrayByParity(vector<int>& nums) {
    vector<int> ret;
    for (auto num : nums) {
      if (num % 2 == 0) {
        ret.push_back(num);
      }
    }
    for (auto num : nums) {
      if (num % 2 == 1) {
        ret.push_back(num);
      }
    }
    return ret;
  }
};
// @lc code=end
