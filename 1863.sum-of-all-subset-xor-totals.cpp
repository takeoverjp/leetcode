/*
 * @lc app=leetcode id=1863 lang=cpp
 *
 * [1863] Sum of All Subset XOR Totals
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int subsetXORSum(vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }
    int ret = 0;
    for (const auto num : nums) {
      ret |= num;
    }
    return ret * (1 << (nums.size() - 1));
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  ASSERT_EQ(s.subsetXORSum(nums), 0);
  nums = {1, 3};
  ASSERT_EQ(s.subsetXORSum(nums), 6);
  nums = {5, 1, 6};
  ASSERT_EQ(s.subsetXORSum(nums), 28);
  nums = {3, 4, 5, 6, 7, 8};
  ASSERT_EQ(s.subsetXORSum(nums), 480);
  return 0;
}
