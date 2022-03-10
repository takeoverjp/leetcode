/*
 * @lc app=leetcode id=1837 lang=cpp
 *
 * [1837] Sum of Digits in Base K
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int sumBase(int n, int k) {
    int ret = 0;
    while (n) {
      ret += n % k;
      n /= k;
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.sumBase(34, 6), 9);
  ASSERT_EQ(s.sumBase(10, 10), 1);
  return 0;
}
