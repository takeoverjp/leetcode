/*
 * @lc app=leetcode id=1629 lang=cpp
 *
 * [1629] Slowest Key
 */

// @lc code=start
class Solution {
 public:
  char slowestKey(vector<int>& releaseTimes, string keysPressed) {
    int size = releaseTimes.size();
    char ret = keysPressed[0];
    int longest = releaseTimes[0];
    for (int i = 1; i < size; i++) {
      int duration = releaseTimes[i] - releaseTimes[i - 1];
      if (duration > longest) {
        longest = duration;
        ret = keysPressed[i];
      } else if (duration == longest) {
        ret = max(keysPressed[i], ret);
      }
    }
    return ret;
  }
};
// @lc code=end
