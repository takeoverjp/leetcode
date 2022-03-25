/*
 * @lc app=leetcode id=1920 lang=cpp
 *
 * [1920] Build Array from Permutation
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> buildArray(vector<int>& nums) {
    int size = nums.size();
    vector<int> ret(size);
    for (int i = 0; i < size; i++) {
      ret[i] = nums[nums[i]];
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums, exp;
  nums = {0, 2, 1, 5, 3, 4};
  exp = {0, 1, 2, 4, 5, 3};
  ASSERT_EQ(s.buildArray(nums), exp);
  nums = {5, 0, 1, 2, 3, 4};
  exp = {4, 5, 0, 1, 2, 3};
  ASSERT_EQ(s.buildArray(nums), exp);
  return 0;
}
