/*
 * @lc app=leetcode id=693 lang=cpp
 *
 * [693] Binary Number with Alternating Bits
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool hasAlternatingBits(int n) {
    uint u = static_cast<uint>(n);
    uint state = u & 1;
    uint index = 1;
    while ((1U << index) < u) {
      if (((u >> index) & 1) == state) {
        return false;
      }
      ++index;
      state = state ? 0 : 1;
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.hasAlternatingBits(1), true);
  ASSERT_EQ(s.hasAlternatingBits(5), true);
  ASSERT_EQ(s.hasAlternatingBits(7), false);
  ASSERT_EQ(s.hasAlternatingBits(11), false);
  ASSERT_EQ(s.hasAlternatingBits(10), true);
  ASSERT_EQ(s.hasAlternatingBits(3), false);
  ASSERT_EQ(s.hasAlternatingBits(INT_MAX), false);
  return 0;
}
