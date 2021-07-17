/*
 * @lc app=leetcode id=495 lang=cpp
 *
 * [495] Teemo Attacking
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int size = timeSeries.size();
    int ret = 0;
    for (int i = 0; i < size - 1; i++) {
      ret += std::min(timeSeries[i + 1] - timeSeries[i], duration);
    }
    if (size > 0) {
      ret += duration;
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> timeSeries;
  timeSeries = {0};
  ASSERT_EQ(s.findPoisonedDuration(timeSeries, 0), 0);
  timeSeries = {1, 4};
  ASSERT_EQ(s.findPoisonedDuration(timeSeries, 2), 4);
  timeSeries = {1, 2};
  ASSERT_EQ(s.findPoisonedDuration(timeSeries, 2), 3);
  timeSeries = {1, 1, 4};
  ASSERT_EQ(s.findPoisonedDuration(timeSeries, 2), 4);
  return 0;
}
