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
    uint chrs = std::set<char>(s.begin(), s.end()).size();
    uint len = s.length();
    for (int width = chrs; width >= 0; width--) {
      for (uint i = 0; i <= len - width; i++) {
        if (static_cast<uint>(width) ==
            std::set<char>(s.begin() + i, s.begin() + i + width).size()) {
          return width;
        }
      }
    }
    return 0;
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
