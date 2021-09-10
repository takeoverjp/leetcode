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
    vector<int> count(101, 0);
    for (const int num : nums) {
      count[num]++;
    }
    for (int i = 1; i < 101; i++) {
      count[i] += count[i - 1];
    }
    for (int i = 0; i < size; i++) {
      ret[i] = (nums[i] > 0) ? count[nums[i] - 1] : 0;
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
  nums = {5, 0, 10, 0, 10, 6};
  exp = {2, 0, 4, 0, 4, 3};
  ASSERT_EQ(s.smallerNumbersThanCurrent(nums), exp);
  return 0;
}
