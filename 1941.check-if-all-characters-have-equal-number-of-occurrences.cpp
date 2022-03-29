/*
 * @lc app=leetcode id=1941 lang=cpp
 *
 * [1941] Check if All Characters Have Equal Number of Occurrences
 */

// @lc code=start
class Solution {
 public:
  bool areOccurrencesEqual(string s) {
    int count[26] = {0};
    for (const auto c : s) {
      count[c - 'a']++;
    }
    int cnt = 0;
    for (int i = 0; i < 26; i++) {
      if (!count[i]) {
        continue;
      }
      if (!cnt) {
        cnt = count[i];
        continue;
      }
      if (cnt != count[i]) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
