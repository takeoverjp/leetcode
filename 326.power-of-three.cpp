/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 */

// @lc code=start
class Solution {
 public:
  bool isPowerOfThree(int n) {
    if (n == 0) {
      return false;
    }
    if (n == 1) {
      return true;
    }
    if (n % 3) {
      return false;
    }
    return isPowerOfThree(n / 3);
  }
};
// @lc code=end
