/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
 public:
  bool isAnagram(string s, string t) {
    int len = s.length();
    if (len != t.length()) {
      return false;
    }
    int count[26] = {0};
    for (int i = 0; i < len; i++) {
      count[s[i] - 'a']++;
      count[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
      if (count[i]) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
