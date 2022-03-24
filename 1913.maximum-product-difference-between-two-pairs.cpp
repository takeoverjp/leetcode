/*
 * @lc app=leetcode id=1913 lang=cpp
 *
 * [1913] Maximum Product Difference Between Two Pairs
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int maxProductDifference(vector<int>& nums) {
    sort(begin(nums), end(nums));
    return nums[nums.size() - 1] * nums[nums.size() - 2] - nums[0] * nums[1];
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {5, 6, 2, 7, 4};
  ASSERT_EQ(s.maxProductDifference(nums), 34);
  nums = {4, 2, 5, 9, 7, 4, 8};
  ASSERT_EQ(s.maxProductDifference(nums), 64);
  return 0;
}
