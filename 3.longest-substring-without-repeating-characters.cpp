/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int last_pos[256] = {0};
    int left = 0;
    int len = s.length();
    int ret = 0;
    for (int right = 0; right < len; right++) {
      if (last_pos[s[right]] > 0) {
        left = max(left, last_pos[s[right]]);
      }
      last_pos[s[right]] = right + 1;
      ret = max(ret, right - left + 1);
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.lengthOfLongestSubstring("abcabcbb"), 3);
  ASSERT_EQ(s.lengthOfLongestSubstring("bbbbb"), 1);
  ASSERT_EQ(s.lengthOfLongestSubstring("pwwkew"), 3);
  ASSERT_EQ(s.lengthOfLongestSubstring(""), 0);
  ASSERT_EQ(s.lengthOfLongestSubstring("a"), 1);
  ASSERT_EQ(s.lengthOfLongestSubstring(" "), 1);
  return 0;
}
