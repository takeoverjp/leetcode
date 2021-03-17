/*
 * @lc app=leetcode id=665 lang=cpp
 *
 * [665] Non-decreasing Array
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool checkPossibility(vector<int>& nums) {
    int count = 0;
    int size = nums.size();
    for (int i = 0; i < size - 1; i++) {
      if (nums[i] <= nums[i + 1]) {
        continue;
      }
      count++;
      if (count >= 2) {
        return false;
      }
      bool ok_by_modify_curr = (i < 1) || (nums[i - 1] <= nums[i + 1]);
      bool ok_by_modify_next = (i >= size - 2) || (nums[i] <= nums[i + 2]);
      if (!ok_by_modify_curr && !ok_by_modify_next) {
          return false;
      }
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {4, 2, 3};
  ASSERT_EQ(s.checkPossibility(nums), true);
  nums = {4, 2, 1};
  ASSERT_EQ(s.checkPossibility(nums), false);
  nums = {3, 4, 2, 3};
  ASSERT_EQ(s.checkPossibility(nums), false);
  nums = {5, 7, 1, 8};
  ASSERT_EQ(s.checkPossibility(nums), true);
  return 0;
}
