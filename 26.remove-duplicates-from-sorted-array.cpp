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
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    return nums.size();
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums, exp;

  nums = {1, 1, 2};
  exp = {1, 2};
  ASSERT_EQ(s.removeDuplicates(nums), 2);
  ASSERT_EQ(nums, exp);

  nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  exp = {0, 1, 2, 3, 4};
  ASSERT_EQ(s.removeDuplicates(nums), 5);
  ASSERT_EQ(nums, exp);

  return 0;
}
