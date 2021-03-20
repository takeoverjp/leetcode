/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int findLengthOfLCIS(vector<int>& nums) {
    int size = nums.size();
    if (size <= 1) {
      return size;
    }
    int last = nums[0];
    int longest = 1;
    int current = 1;
    for (int i = 1; i < size; i++) {
      if (nums[i] > last) {
        current++;
        longest = max(longest, current);
      } else {
        current = 1;
      }
      last = nums[i];
    }

    return longest;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {};
  ASSERT_EQ(s.findLengthOfLCIS(nums), 0);
  nums = {1};
  ASSERT_EQ(s.findLengthOfLCIS(nums), 1);
  nums = {1, 3, 5, 4, 7};
  ASSERT_EQ(s.findLengthOfLCIS(nums), 3);
  nums = {2, 2, 2, 2, 2};
  ASSERT_EQ(s.findLengthOfLCIS(nums), 1);
  return 0;
}
