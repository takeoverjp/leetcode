/*
 * @lc app=leetcode id=1523 lang=cpp
 *
 * [1523] Count Odd Numbers in an Interval Range
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int countOdds(int low, int high) {
    int interval = high - low;
    if (interval % 2) {
      return (interval + 1) / 2;
    } else {
      if (low % 2) {
        return interval / 2 + 1;
      } else {
        return interval / 2;
      }
    }
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.countOdds(3, 7), 3);
  ASSERT_EQ(s.countOdds(3, 6), 2);
  ASSERT_EQ(s.countOdds(8, 10), 1);
  return 0;
}
