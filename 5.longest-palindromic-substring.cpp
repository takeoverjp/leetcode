/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string longestPalindrome(string s) {
    int len = s.length();
    int max_len = 1;
    int max_start = 0;
    for (int start = 0; start < len; start++) {
      for (int end = len - 1; end - start + 1 > max_len; end--) {
        if (isPalindrom(s, start, end)) {
          max_len = end - start + 1;
          max_start = start;
        }
      }
    }
    return s.substr(max_start, max_len);
  }

 private:
  bool isPalindrom(const string& s, int start, int end) {
    for (int i = 0; i < (end - start + 1) / 2; i++) {
      if (s[start + i] != s[end - i]) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.longestPalindrome("babad"), "bab");
  ASSERT_EQ(s.longestPalindrome("cbbd"), "bb");
  ASSERT_EQ(s.longestPalindrome("a"), "a");
  ASSERT_EQ(s.longestPalindrome("ac"), "a");
  return 0;
}
