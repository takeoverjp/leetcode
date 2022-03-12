/*
 * @lc app=leetcode id=1848 lang=cpp
 *
 * [1848] Minimum Distance to the Target Element
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int getMinDistance(vector<int>& nums, int target, int start) {
    int ret = INT_MAX;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      if (nums[i] == target) {
        ret = min(ret, abs(i - start));
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {1, 2, 3, 4, 5};
  ASSERT_EQ(s.getMinDistance(nums, 5, 3), 1);
  nums = {1};
  ASSERT_EQ(s.getMinDistance(nums, 1, 0), 0);
  nums = {1, 1, 1, 1, 1, 1, 1, 1, 1};
  ASSERT_EQ(s.getMinDistance(nums, 1, 0), 0);
  return 0;
}
