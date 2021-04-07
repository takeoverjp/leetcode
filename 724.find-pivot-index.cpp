/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    int left = 0;
    int right = -1 * nums[0];
    int size = nums.size();
    for (auto n : nums) {
      right += n;
    }
    if (left == right) {
      return 0;
    }
    for (int i = 1; i < size; i++) {
      left += nums[i - 1];
      right -= nums[i];
      if (left == right) {
        return i;
      }
    }
    return -1;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {1};
  ASSERT_EQ(s.pivotIndex(nums), 0);
  nums = {1, 7, 3, 6, 5, 6};
  ASSERT_EQ(s.pivotIndex(nums), 3);
  nums = {1, 2, 3};
  ASSERT_EQ(s.pivotIndex(nums), -1);
  nums = {2, 1, -1};
  ASSERT_EQ(s.pivotIndex(nums), 0);
  return 0;
}
