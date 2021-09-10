/*
 * @lc app=leetcode id=1365 lang=cpp
 *
 * [1365] How Many Numbers Are Smaller Than the Current Number
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    int size = nums.size();
    vector<int> ret(size);
    for (int i = 0; i < size; i++) {
      const int num = nums[i];
      ret[i] = std::count_if(std::begin(nums), std::end(nums),
                             [num](const auto i) { return i < num; });
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums, exp;
  nums = {8, 1, 2, 2, 3};
  exp = {4, 0, 1, 1, 3};
  ASSERT_EQ(s.smallerNumbersThanCurrent(nums), exp);
  nums = {6, 5, 4, 8};
  exp = {2, 1, 0, 3};
  ASSERT_EQ(s.smallerNumbersThanCurrent(nums), exp);
  nums = {7, 7, 7, 7};
  exp = {0, 0, 0, 0};
  ASSERT_EQ(s.smallerNumbersThanCurrent(nums), exp);
  return 0;
}
