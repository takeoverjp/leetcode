/*
 * @lc app=leetcode id=1009 lang=cpp
 *
 * [1009] Complement of Base 10 Integer
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int bitwiseComplement(int n) {
    if (n == 0) {
      return 1;
    }
    int ret = 0;
    int count = 0;
    while (n) {
      ret |= ((n & 1) ? 0 : 1) << count;
      n >>= 1;
      count++;
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.bitwiseComplement(0), 1);
  ASSERT_EQ(s.bitwiseComplement(5), 2);
  ASSERT_EQ(s.bitwiseComplement(7), 0);
  ASSERT_EQ(s.bitwiseComplement(10), 5);
  return 0;
}
