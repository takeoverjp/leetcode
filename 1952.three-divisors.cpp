/*
 * @lc app=leetcode id=1952 lang=cpp
 *
 * [1952] Three Divisors
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool isThree(int n) {
    int s = sqrt(n);
    if (n == 1 || n != (s * s)) {
      return false;
    }
    for (int i = 2; i < s; i++) {
      if (s % i == 0) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.isThree(2), false);
  ASSERT_EQ(s.isThree(4), true);
  ASSERT_EQ(s.isThree(81), false);
  return 0;
}
