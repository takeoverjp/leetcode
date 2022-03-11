/*
 * @lc app=leetcode id=1844 lang=cpp
 *
 * [1844] Replace All Digits with Characters
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string replaceDigits(string s) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
      if (i % 2) {
        s[i] = s[i - 1] + (s[i] - '0');
      }
    }
    return s;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.replaceDigits("a1c1e1"), "abcdef");
  ASSERT_EQ(s.replaceDigits("a1b2c3d4e"), "abbdcfdhe");
  return 0;
}
