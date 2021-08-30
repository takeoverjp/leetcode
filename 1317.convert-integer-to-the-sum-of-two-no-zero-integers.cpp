/*
 * @lc app=leetcode id=1317 lang=cpp
 *
 * [1317] Convert Integer to the Sum of Two No-Zero Integers
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> getNoZeroIntegers(int n) {
    int ret = 1;
    while (ret < n) {
      if (!is_zero_number(ret) && !is_zero_number(n - ret)) {
        return vector<int>{ret, n - ret};
      }
      ret++;
    }
    return vector<int>{ret, n - ret};
  }

 private:
  bool is_zero_number(int n) {
    while (n) {
      if (n % 10 == 0) {
        return true;
      }
      n /= 10;
    }
    return false;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> exp;
  exp = {2, 9};
  ASSERT_EQ(s.getNoZeroIntegers(11), exp);
  return 0;
}
