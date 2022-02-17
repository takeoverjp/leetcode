/*
 * @lc app=leetcode id=1732 lang=cpp
 *
 * [1732] Find the Highest Altitude
 */

// @lc code=start
class Solution {
 public:
  int largestAltitude(vector<int>& gain) {
    int altitude = 0;
    int ret = 0;
    for (const auto diff : gain) {
      altitude += diff;
      ret = max(ret, altitude);
    }
    return ret;
  }
};
// @lc code=end
