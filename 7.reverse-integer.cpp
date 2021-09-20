/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int reverse(int x) {
    long y = 0;
    while (x) {
      y = y * 10 + x % 10;
      x /= 10;
    }
    return (y >= INT32_MAX || y <= INT32_MIN) ? 0 : y;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.reverse(123), 321);
  ASSERT_EQ(s.reverse(-123), -321);
  ASSERT_EQ(s.reverse(120), 21);
  ASSERT_EQ(s.reverse(0), 0);
  return 0;
}
