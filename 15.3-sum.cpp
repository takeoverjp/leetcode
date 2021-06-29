/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    int size = nums.size();
    for (int left = 0; (left + 2 < size) && nums[left] <= 0; left++) {
      if (left != 0 && nums[left] == nums[left - 1]) {
        continue;
      }
      for (int right = size - 1; (right > left + 1) && nums[right] >= 0;
           right--) {
        if (right != size - 1 && nums[right] == nums[right + 1]) {
          continue;
        }
        int middle = 0 - nums[left] - nums[right];
        if (binary_search(nums.begin() + left + 1, nums.begin() + right,
                          middle)) {
          ret.push_back({nums[left], middle, nums[right]});
        }
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  vector<vector<int>> exp;
  nums = {-1, 0, 1, 2, -1, -4};
  exp = {{-1, -1, 2}, {-1, 0, 1}};
  ASSERT_EQ(s.threeSum(nums), exp);
  nums = {};
  exp = {};
  ASSERT_EQ(s.threeSum(nums), exp);
  nums = {0};
  exp = {};
  ASSERT_EQ(s.threeSum(nums), exp);
  nums = {0, 0, 0};
  exp = {{0, 0, 0}};
  ASSERT_EQ(s.threeSum(nums), exp);
  nums = {0, 0, 0, 0};
  exp = {{0, 0, 0}};
  ASSERT_EQ(s.threeSum(nums), exp);
  return 0;
}
