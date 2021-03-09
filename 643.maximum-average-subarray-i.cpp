/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  double findMaxAverage(vector<int>& nums, int k) {
    int64_t max = INT64_MIN;
    int size = nums.size();

    int64_t sum = 0;
    for (int i = 0; i < k; i++) {
      sum += nums[i];
    }
    max = std::max(max, sum);
    for (int i = 1; i < size - k + 1; i++) {
      sum = sum - nums[i - 1] + nums[i + k - 1];
      max = std::max(max, sum);
    }
    return static_cast<double>(max) / k;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {1, 12, -5, -6, 50, 3};
  ASSERT_EQ(s.findMaxAverage(nums, 4), 12.75);
  nums = {5};
  ASSERT_EQ(s.findMaxAverage(nums, 1), 5);
  nums = {0, 1, 1, 3, 3};
  ASSERT_EQ(s.findMaxAverage(nums, 4), 2);
  return 0;
}
