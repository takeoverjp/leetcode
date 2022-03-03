/*
 * @lc app=leetcode id=1800 lang=cpp
 *
 * [1800] Maximum Ascending Subarray Sum
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int maxAscendingSum(vector<int>& nums) {
    int ret = 0;
    int last = 0;
    int sum = 0;
    for (const auto num : nums) {
      if (num > last) {
        sum += num;
        ret = max(ret, sum);
      } else {
        sum = num;
      }
      last = num;
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {10, 20, 30, 5, 10, 50};
  ASSERT_EQ(s.maxAscendingSum(nums), 65);
  nums = {10, 20, 30, 40, 50};
  ASSERT_EQ(s.maxAscendingSum(nums), 150);
  nums = {12, 17, 15, 13, 10, 11, 12};
  ASSERT_EQ(s.maxAscendingSum(nums), 33);
  return 0;
}
