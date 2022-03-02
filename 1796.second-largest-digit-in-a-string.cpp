/*
 * @lc app=leetcode id=1796 lang=cpp
 *
 * [1796] Second Largest Digit in a String
 */

// @lc code=start
class Solution {
 public:
  int secondHighest(string s) {
    int largest = -1;
    int second = -1;
    for (const auto c : s) {
      if (isdigit(c)) {
        int num = c - '0';
        if (num > largest) {
          second = largest;
          largest = num;
        } else if (num > second && num < largest) {
          second = num;
        }
      }
    }
    return second;
  }
};
// @lc code=end
