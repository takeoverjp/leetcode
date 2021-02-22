/*
 * @lc app=leetcode id=561 lang=cpp
 *
 * [561] Array Partition I
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int arrayPairSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    int size = nums.size();
    int ret = 0;
    for (int i = 0; i < size; i += 2) {
      ret += nums[i];
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {1, 4, 3, 2};
  ASSERT_EQ(s.arrayPairSum(nums), 4);
  nums = {6, 2, 6, 5, 1, 2};
  ASSERT_EQ(s.arrayPairSum(nums), 9);
  return 0;
}
