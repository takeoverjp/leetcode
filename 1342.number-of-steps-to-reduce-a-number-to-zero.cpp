/*
 * @lc app=leetcode id=1342 lang=cpp
 *
 * [1342] Number of Steps to Reduce a Number to Zero
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int numberOfSteps(int num) {
    int ret = 0;
    while (num) {
      if (num % 2) {
        num--;
      } else {
        num /= 2;
      }
      ret++;
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.numberOfSteps(14), 6);
  ASSERT_EQ(s.numberOfSteps(8), 4);
  return 0;
}
