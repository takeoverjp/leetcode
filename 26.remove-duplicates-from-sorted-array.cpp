/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    return std::unique(nums.begin(), nums.end()) - nums.begin();
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums, exp;

  nums = {1, 1, 2};
  exp = {1, 2};
  ASSERT_EQ(s.removeDuplicates(nums), 2);
  for (int i = 0; i < 2; i++) {
    ASSERT_EQ(nums[i], exp[i]);
  }

  nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  exp = {0, 1, 2, 3, 4};
  ASSERT_EQ(s.removeDuplicates(nums), 5);
  for (int i = 0; i < 5; i++) {
    ASSERT_EQ(nums[i], exp[i]);
  }

  return 0;
}
