/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      nums[i] = nums[i] * nums[i];
    }
    sort(nums.begin(), nums.end());
    return nums;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums, exp;
  nums = {-4, -1, 0, 3, 10};
  exp = {0, 1, 9, 16, 100};
  ASSERT_EQ(s.sortedSquares(nums), exp);
  nums = {-7, -3, 2, 3, 11};
  exp = {4, 9, 9, 49, 121};
  ASSERT_EQ(s.sortedSquares(nums), exp);
  return 0;
}
