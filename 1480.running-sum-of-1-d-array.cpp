/*
 * @lc app=leetcode id=1480 lang=cpp
 *
 * [1480] Running Sum of 1d Array
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> runningSum(vector<int>& nums) {
    int size = nums.size();
    for (int i = 1; i < size; i++) {
      nums[i] += nums[i - 1];
    }
    return nums;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums, exp;
  nums = {1, 2, 3, 4};
  exp = {1, 3, 6, 10};
  ASSERT_EQ(s.runningSum(nums), exp);
  nums = {1, 1, 1, 1, 1};
  exp = {1, 2, 3, 4, 5};
  ASSERT_EQ(s.runningSum(nums), exp);
  nums = {3, 1, 2, 10, 1};
  exp = {3, 4, 6, 16, 17};
  ASSERT_EQ(s.runningSum(nums), exp);
  return 0;
}
