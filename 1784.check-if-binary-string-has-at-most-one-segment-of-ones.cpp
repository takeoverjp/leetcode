/*
 * @lc app=leetcode id=1784 lang=cpp
 *
 * [1784] Check if Binary String Has at Most One Segment of Ones
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool checkOnesSegment(string s) {
    int count = 0;
    bool in_zero = true;
    for (const auto c : s) {
      if (c == '1') {
        if (in_zero) {
          count++;
          in_zero = false;
          if (count >= 2) {
            return false;
          }
        } else {
          continue;
        }
      } else {
        in_zero = true;
      }
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.checkOnesSegment("1001"), false);
  ASSERT_EQ(s.checkOnesSegment("110"), true);
  ASSERT_EQ(s.checkOnesSegment("1"), true);
  return 0;
}
