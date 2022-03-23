/*
 * @lc app=leetcode id=1909 lang=cpp
 *
 * [1909] Remove One Element to Make the Array Strictly Increasing
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool canBeIncreasing(vector<int>& nums) {
    int last = nums[0];
    int count = 0;
    for (int i = 1; i < nums.size(); i++) {
      if (last < nums[i]) {
        last = nums[i];
        continue;
      }
      if (count >= 1) {
        return false;
      }
      count++;
      if (i == 1 || nums[i] > nums[i - 2]) {
        last = nums[i];
      }
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {1, 2, 10, 5, 7};
  ASSERT_EQ(s.canBeIncreasing(nums), true);
  nums = {2, 3, 1, 2};
  ASSERT_EQ(s.canBeIncreasing(nums), false);
  nums = {1, 1, 1};
  ASSERT_EQ(s.canBeIncreasing(nums), false);
  return 0;
}
