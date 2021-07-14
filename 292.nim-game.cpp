/*
 * @lc app=leetcode id=292 lang=cpp
 *
 * [292] Nim Game
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool canWinNim(int n) {
    return n % 4 != 0;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.canWinNim(1), true);
  ASSERT_EQ(s.canWinNim(2), true);
  ASSERT_EQ(s.canWinNim(3), true);
  ASSERT_EQ(s.canWinNim(4), false);
  ASSERT_EQ(s.canWinNim(5), true);
  ASSERT_EQ(s.canWinNim(6), true);
  ASSERT_EQ(s.canWinNim(7), true);
  ASSERT_EQ(s.canWinNim(8), false);
  return 0;
}
