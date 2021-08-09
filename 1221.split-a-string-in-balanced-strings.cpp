/*
 * @lc app=leetcode id=1221 lang=cpp
 *
 * [1221] Split a String in Balanced Strings
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int balancedStringSplit(string s) {
    int l = 0;
    int r = 0;
    int ret = 0;
    for (const char c : s) {
      if (c == 'L') {
        l++;
      } else {
        r++;
      }
      if (l == r) {
        l = 0;
        r = 0;
        ret++;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.balancedStringSplit("RLRRLLRLRL"), 4);
  ASSERT_EQ(s.balancedStringSplit("RLLLLRRRLR"), 3);
  ASSERT_EQ(s.balancedStringSplit("LLLLRRRR"), 1);
  ASSERT_EQ(s.balancedStringSplit("RLRRRLLRLL"), 2);
  return 0;
}
