/*
 * @lc app=leetcode id=1742 lang=cpp
 *
 * [1742] Maximum Number of Balls in a Box
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int countBalls(int lowLimit, int highLimit) {
    int ret = 0;
    unordered_map<int, int> count;
    for (int i = lowLimit; i <= highLimit; i++) {
      int sum = 0;
      int work = i;
      while (work) {
        sum += work % 10;
        work /= 10;
      }
      ret = max(ret, ++count[sum]);
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.countBalls(1, 10), 2);
  ASSERT_EQ(s.countBalls(5, 15), 2);
  ASSERT_EQ(s.countBalls(19, 28), 2);
  return 0;
}
