/*
 * @lc app=leetcode id=1413 lang=cpp
 *
 * [1413] Minimum Value to Get Positive Step by Step Sum
 */
#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int minStartValue(vector<int>& nums) {
    int sum = 0;
    int min_sum = INT_MAX;
    for (auto num : nums) {
      sum += num;
      min_sum = min(min_sum, sum);
    }
    return (min_sum < 0) ? (1 - min_sum) : 1;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {-3, 2, -3, 4, 2};
  ASSERT_EQ(s.minStartValue(nums), 5);
  nums = {1, 2};
  ASSERT_EQ(s.minStartValue(nums), 1);
  nums = {1, -2, -3};
  ASSERT_EQ(s.minStartValue(nums), 5);
  return 0;
}
