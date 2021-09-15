/*
 * @lc app=leetcode id=1389 lang=cpp
 *
 * [1389] Create Target Array in the Given Order
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    vector<int> ret;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      int num = nums[i];
      int idx = index[i];
      ret.insert(ret.begin() + idx, num);
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums, index, exp;
  nums = {0, 1, 2, 3, 4};
  index = {0, 1, 2, 2, 1};
  exp = {0, 4, 1, 3, 2};
  ASSERT_EQ(s.createTargetArray(nums, index), exp);
  nums = {1, 2, 3, 4, 0};
  index = {0, 1, 2, 3, 0};
  exp = {0, 1, 2, 3, 4};
  ASSERT_EQ(s.createTargetArray(nums, index), exp);
  nums = {1};
  index = {0};
  exp = {1};
  ASSERT_EQ(s.createTargetArray(nums, index), exp);
  return 0;
}
