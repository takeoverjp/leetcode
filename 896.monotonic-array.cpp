/*
 * @lc app=leetcode id=896 lang=cpp
 *
 * [896] Monotonic Array
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool isMonotonic(vector<int>& nums) {
    int len = nums.size();
    if (len == 1) {
      return true;
    }
    int i = 0;
    while (nums[i] == nums[i + 1]) {
      if (i + 2 == len) {
        return true;
      }
      i++;
    }
    bool is_inc = (nums[i] > nums[i + 1]);
    for (int j = i; j + 1 < len; j++) {
      if (is_inc) {
        if (nums[j] < nums[j + 1]) {
          return false;
        }
      } else {
        if (nums[j] > nums[j + 1]) {
          return false;
        }
      }
    }
    return true;
  }
};
// @lc code=end

int
main () {
  Solution s;
  vector<int> nums;
  nums = {1, 1};
  ASSERT_EQ(s.isMonotonic(nums), true);
  return 0;
}
