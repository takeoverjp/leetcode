/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int len = nums.size();
    int64_t global_sum_max = INT32_MIN;
    int64_t current_sum_max = INT32_MIN;
    for (int i = 0; i < len; i++) {
      current_sum_max =
          max(static_cast<int64_t>(nums[i]), current_sum_max + nums[i]);
      global_sum_max = max(global_sum_max, current_sum_max);
      // std::cerr << current_sum_max << " " << global_sum_max << std::endl;
    }
    return global_sum_max;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  assert(s.maxSubArray(nums) == 6);
  nums = {1};
  assert(s.maxSubArray(nums) == 1);
  nums = {0};
  assert(s.maxSubArray(nums) == 0);
  nums = {-1};
  assert(s.maxSubArray(nums) == -1);
  nums = {-2147483647};
  assert(s.maxSubArray(nums) == -2147483647);
  nums = {-2147483647, -1};
  assert(s.maxSubArray(nums) == -1);
  return 0;
}
