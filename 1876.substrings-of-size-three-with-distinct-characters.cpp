/*
 * @lc app=leetcode id=1876 lang=cpp
 *
 * [1876] Substrings of Size Three with Distinct Characters
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int countGoodSubstrings(string s) {
    int len = s.length();
    int ret = 0;
    for (int i = 0; i < len - 2; i++) {
      if (s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i + 2] != s[i]) {
        ret++;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.countGoodSubstrings("xyzzaz"), 1);
  ASSERT_EQ(s.countGoodSubstrings("aababcabc"), 4);
  return 0;
}
