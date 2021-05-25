/*
 * @lc app=leetcode id=908 lang=cpp
 *
 * [908] Smallest Range I
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int smallestRangeI(vector<int>& nums, int k) {
    if (nums.size() == 0) {
      return 0;
    }
    int min_num = 10000;
    int max_num = 0;
    for (auto num : nums) {
      min_num = std::min(min_num, num);
      max_num = std::max(max_num, num);
    }
    int diff = max_num - min_num;
    if (k * 2 >= diff) {
      return 0;
    }
    return diff - k * 2;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {1};
  ASSERT_EQ(s.smallestRangeI(nums, 0), 0);
  nums = {0, 10};
  ASSERT_EQ(s.smallestRangeI(nums, 2), 6);
  nums = {1, 3, 6};
  ASSERT_EQ(s.smallestRangeI(nums, 3), 0);
  return 0;
}
