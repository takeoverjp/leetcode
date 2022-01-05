/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
      return INT_MAX;
    }
    bool is_neg = (dividend < 0) ^ (divisor < 0);
    uint64_t ret = 0;
    uint64_t ldividend = labs(dividend);
    uint64_t ldivisor = labs(divisor);
    for (int i = 31; i >= 0; i--) {
      if (ldividend >= ldivisor << i) {
        ret += 1 << i;
        ldividend -= ldivisor << i;
      }
    }
    return is_neg ? (-ret) : ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.divide(1, 1), 1);
  ASSERT_EQ(s.divide(10, 3), 3);
  ASSERT_EQ(s.divide(7, -3), -2);
  ASSERT_EQ(s.divide(-2147483648, -1), 2147483647);
  ASSERT_EQ(s.divide(-2147483648, 1), -2147483648);
  ASSERT_EQ(s.divide(2147483647, 1), 2147483647);
  return 0;
}
