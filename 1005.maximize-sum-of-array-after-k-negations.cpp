/*
 * @lc app=leetcode id=1005 lang=cpp
 *
 * [1005] Maximize Sum Of Array After K Negations
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int largestSumAfterKNegations(vector<int>& nums, int k) {
    int neg_num = 0;
    for (const auto& num : nums) {
      if (num < 0) {
        neg_num++;
      }
    }
    if (k >= neg_num) {
      for (auto& num : nums) {
        if (num < 0) {
          num = -1 * num;
        }
      }
      k -= neg_num;
      k %= 2;
      if (k == 0) {
        return accumulate(nums.begin(), nums.end(), 0);
      }

      int min_num = INT_MAX;
      for (const auto& num : nums) {
        min_num = min(min_num, num);
      }
      return accumulate(nums.begin(), nums.end(), -2 * min_num);
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < k; i++) {
      nums[i] = -1 * nums[i];
    }
    return accumulate(nums.begin(), nums.end(), 0);
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {3, -1, 0, 2};
  ASSERT_EQ(s.largestSumAfterKNegations(nums, 3), 6);
  nums = {4, 2, 3};
  ASSERT_EQ(s.largestSumAfterKNegations(nums, 1), 5);
  nums = {2, -3, -1, 5, -4};
  ASSERT_EQ(s.largestSumAfterKNegations(nums, 2), 13);
  return 0;
}
