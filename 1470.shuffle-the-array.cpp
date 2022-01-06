/*
 * @lc app=leetcode id=1470 lang=cpp
 *
 * [1470] Shuffle the Array
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> ret(2 * n);
    for (int i = 0; i < n; i++) {
      ret[2 * i] = nums[i];
      ret[2 * i + 1] = nums[i + n];
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums, exp;
  nums = {2, 5, 1, 3, 4, 7};
  exp = {2, 3, 5, 4, 1, 7};
  ASSERT_EQ(s.shuffle(nums, nums.size() / 2), exp);
  nums = {1, 2, 3, 4, 4, 3, 2, 1};
  exp = {1, 4, 2, 3, 3, 2, 4, 1};
  ASSERT_EQ(s.shuffle(nums, nums.size() / 2), exp);
  nums = {1, 1, 2, 2};
  exp = {1, 2, 1, 2};
  ASSERT_EQ(s.shuffle(nums, nums.size() / 2), exp);
  return 0;
}
