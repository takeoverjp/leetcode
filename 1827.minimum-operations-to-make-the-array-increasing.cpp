/*
 * @lc app=leetcode id=1827 lang=cpp
 *
 * [1827] Minimum Operations to Make the Array Increasing
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int start = nums[0] + 1;
    int size = nums.size();
    int ret = 0;
    for (int i = 1; i < size; i++) {
      if (nums[i] >= start) {
        start = nums[i] + 1;
      } else {
        ret += start - nums[i];
        start++;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {1, 1, 1};
  ASSERT_EQ(s.minOperations(nums), 3);
  nums = {1, 5, 2, 4, 1};
  ASSERT_EQ(s.minOperations(nums), 14);
  nums = {8};
  ASSERT_EQ(s.minOperations(nums), 0);
  return 0;
}
